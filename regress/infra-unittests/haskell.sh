#! /bin/sh
# $NetBSD: haskell.sh,v 1.1 2020/06/27 10:51:12 rillig Exp $
#
# Tests for mk/haskell.mk.
#

set -eu

. './test.subr'

link_from_pkgsrc() {
	for f in "$@"; do
		mkdir -p "$mocked_pkgsrcdir/$(dirname "$f")"
		rm -f "$mocked_pkgsrcdir/$f"
		ln -s "$pkgsrcdir/$f" "$mocked_pkgsrcdir/$f"
	done
}

test_case_set_up() {

	destdir="$PWD/destdir"
	prefix="$PWD/prefix"
	pkgdir="$mocked_pkgsrcdir/category/package"

	mock_ghc=$(mock_cmd ghc \
		--when-args '-V' --then-output 'The Glorious Glasgow Haskell Compilation System, version 8.8.1'
	)

	mkdir -p "$prefix/bin"
	mv "$mock_ghc" "$prefix/bin/"

	rm -rf "$mocked_pkgsrcdir"
	mkdir -p "$pkgdir"
	cd "$mocked_pkgsrcdir"

	create_file 'mk/bsd.fast.prefs.mk' <<-EOF
		OPSYS=			Opsys
		HASKELL_COMPILER=	ghc
		SHLIB_TYPE=		ELF

		AWK=			awk
		CAT=			cat
		CUT=			cut
		ECHO=			echo
		FIND=			find
		GREP=			grep
		MKDIR=			mkdir -p
		PKGSRC_SETENV=		env
		SORT=			sort
		TRUE=			true
	EOF
	create_file 'lang/ghc88/buildlink3.mk' <<-EOF
		# Nothing essential
	EOF
	create_file 'main.mk' <<EOF
.include "mk/bsd.fast.prefs.mk"

PKGDIR=			\${.:L:tA}
WRKDIR=			$PWD/work
PLIST=			\${WRKDIR}/.PLIST
PREFIX=			$prefix
DESTDIR=		$destdir
PKGSRCDIR=		$pkgsrcdir
RUN=			@set -eu;
ALL_ENV=		ALL_ENV_VAR=value

.include "mk/haskell.mk"
.include "mk/plist/bsd.plist.mk"
.include "mk/misc/show.mk"

show-plist-status: .PHONY
	@echo "PLIST status: "\${_HS_PLIST_STATUS:Q}
EOF

	link_from_pkgsrc 'mk/haskell.mk'
	link_from_pkgsrc 'mk/plist'
	link_from_pkgsrc 'mk/misc'

	cd "$pkgdir"
}


if test_case_begin 'PLIST status: missing'; then

	create_file 'Makefile' <<-EOF
		DISTNAME=	package-1.0

		.include "../../main.mk"
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: missing'

	test_case_end
fi


if test_case_begin 'PLIST status: plain'; then

	# See textproc/hs-cgrep/PLIST, r1.4.

	create_file 'Makefile' <<-EOF
		DISTNAME=	cgrep-6.6.30

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-EOF
		bin/cgrep
		share/doc/x86_64-ghc-8.8.1/cgrep-\${PKGVERSION}/LICENSE
		@pkgdir lib/cgrep-\${PKGVERSION}/ghc-8.8.1
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: plain'

	test_case_end
fi


if test_case_begin 'PLIST status: outdated'; then

	# See devel/hs-hashable/PLIST, r1.1.

	create_file 'Makefile' <<-EOF
		DISTNAME=	hashable-1.3.0.0

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-EOF
		lib/hashable-\${PKGVERSION}/\${HASKELL_VERSION}/Data/Hashable.hi
		lib/hashable-\${PKGVERSION}/\${HASKELL_VERSION}/package-description
		share/doc/hashable-\${PKGVERSION}/LICENSE
		\${PLIST.doc}share/doc/hashable-\${PKGVERSION}/html/Data-Hashable.html
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	# TODO: should be 'outdated' because of 'package-description'
	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: plain'

	test_case_end
fi


if test_case_begin 'PLIST status: lib-ok'; then

	# See devel/hs-hashable/PLIST, r1.3.

	create_file 'Makefile' <<-EOF
		DISTNAME=	hashable-1.3.0.0

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-'EOF'
		${HS_INTF}/package-description
		${HS_INTF}/package-id
		${HS_IMPL}/Data/Hashable.dyn_hi
		lib/${HS_PLATFORM}/libHS${HS_PKGID}-${HS_VER}.so
		${HS_DOCS}/LICENSE
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: lib-ok'

	test_case_end
fi

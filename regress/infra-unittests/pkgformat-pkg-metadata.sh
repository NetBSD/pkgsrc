#! /bin/sh
# $NetBSD: pkgformat-pkg-metadata.sh,v 1.2 2020/05/21 18:48:43 rillig Exp $
#
# Demonstrates how mk/pkgformat/pkg/metadata.mk creates the versioning
# information in +BUILD_VERSION.
#
# As of May 2020, several directories must be prefixed with ${.CURDIR},
# since otherwise +BUILD_VERSION ends up containing corrupt data.
#

set -eu

. './test.subr'

test_case_set_up() {
	create_file 'setup.mk' <<-EOF
		AWK=		awk
		CAT=		cat
		ECHO=		echo
		GREP=		grep
		MKDIR=		mkdir -p
		RM=		rm
		SED=		sed
		SORT=		sort
		TEST=		test

		RUN=		@set -e;
		INIT_SYSTEM=	rc.d
		WRKDIR=		$PWD
		WRKSRC=		$PWD
		PKGSRCDIR=	$mocked_pkgsrcdir
	EOF
}


if test_case_begin 'absolute paths'; then

	wrkdir="$PWD"
	pkgdir="$mocked_pkgsrcdir/category/package"
	mkdir -p "$pkgdir"
	cd "$pkgdir"

	cvsid='$''NetBSD: marker ''$'
	create_file 'Makefile' <<-EOF
		# $cvsid

		PKGDIR=		\${.CURDIR}
		FILESDIR=	\${.CURDIR}/files
		PATCHDIR=	\${.CURDIR}/patches
		DISTINFO_FILE=	\${.CURDIR}/distinfo

		.include "$wrkdir/setup.mk"
		.include "$pkgsrcdir/mk/pkgformat/pkg/metadata.mk"
	EOF
	create_file_lines 'patches/patch-aa' \
		"$cvsid"
	create_file_lines 'files/README' \
		"$cvsid"

	run_bmake 'Makefile' "$wrkdir/.pkgdb/+BUILD_VERSION" \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-empty
	assert_that "$wrkdir/.pkgdb/+BUILD_VERSION" --file-is-lines \
		"category/package/Makefile:	$cvsid" \
		"category/package/files/README:	$cvsid" \
		"category/package/patches/patch-aa:	$cvsid"

	test_case_end
fi


if test_case_begin 'relative paths'; then

	# Up to 2020-05-21, relative paths were stored wrong in the
	# +BUILD_VERSION file.

	wrkdir="$PWD"
	pkgdir="$mocked_pkgsrcdir/category/package"
	mkdir -p "$pkgdir"
	cd "$pkgdir"

	cvsid='$''NetBSD: marker ''$'
	create_file 'Makefile' <<-EOF
		# $cvsid

		PKGDIR=		.
		FILESDIR=	files
		PATCHDIR=	patches
		DISTINFO_FILE=	distinfo

		.include "$wrkdir/setup.mk"
		.include "$pkgsrcdir/mk/pkgformat/pkg/metadata.mk"
	EOF
	create_file_lines 'patches/patch-aa' \
		"$cvsid"
	create_file_lines 'files/README' \
		"$cvsid"

	run_bmake 'Makefile' "$wrkdir/.pkgdb/+BUILD_VERSION" \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-empty
	assert_that "$wrkdir/.pkgdb/+BUILD_VERSION" --file-is-lines \
		"category/package/Makefile:	$cvsid" \
		"category/package/files/README:	$cvsid" \
		"category/package/patches/patch-aa:	$cvsid"

	test_case_end
fi

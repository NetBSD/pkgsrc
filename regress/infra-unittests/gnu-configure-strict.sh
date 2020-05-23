#! /bin/sh
# $NetBSD: gnu-configure-strict.sh,v 1.5 2020/05/23 12:11:33 rillig Exp $
#
# Tests for GNU_CONFIGURE_STRICT handling in mk/configure/gnu-configure.mk.
#

set -eu

. './test.subr'

test_case_set_up() {
	create_file 'setup.mk' <<-EOF
		ECHO=		echo
		FIND=		find
		GREP=		grep
		SED=		sed
		SORT=		sort
		TR=		tr

		RUN=		@set -eu; # be extra strict
		ERROR_MSG=	echo 'error:'

		GNU_CONFIGURE_PREFIX= unused-GNU_CONFIGURE_PREFIX
		PREFIX=		unused-PREFIX
		OPSYS=		NetBSD
		WRKDIR=		$PWD
		WRKSRC=		$PWD

		CONFIGURE_SCRIPT?=	./configure
	EOF
}


if test_case_begin 'single configure'; then

	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.
		CONFIGURE_ARGS=		--enable-known
		CONFIGURE_ARGS+=	--disable-known
		CONFIGURE_ARGS+=	--with-known
		CONFIGURE_ARGS+=	--without-known

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF
	create_file 'configure' <<-EOF
		enable_known
		with_known
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-empty

	test_case_end
fi


if test_case_begin 'neither --enable nor --with given'; then

	# Make sure that there is no shell syntax error in the for loop.
	#
	# This test also covers the case where the configure script has
	# some options that are not mentioned in CONFIGURE_ARGS.

	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF
	create_file 'configure' <<-EOF
		enable_known
		with_known
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-empty

	test_case_end
fi


if test_case_begin 'some unknown options'; then

	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.

		CONFIGURE_ARGS=		--enable-unknown-1
		CONFIGURE_ARGS+=	--disable-unknown-2
		CONFIGURE_ARGS+=	--with-unknown-3
		CONFIGURE_ARGS+=	--without-unknown-4

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF
	create_file 'configure' <<-EOF
		enable_known
		with_known
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '1'
	assert_that "$tmpdir/output" --file-is-lines \
		'error: [gnu-configure.mk] option --enable-unknown-1 not found in ./configure' \
		'error: [gnu-configure.mk] option --disable-unknown-2 not found in ./configure' \
		'error: [gnu-configure.mk] option --with-unknown-3 not found in ./configure' \
		'error: [gnu-configure.mk] option --without-unknown-4 not found in ./configure' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin 'unknown options in multiple configures'; then

	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.

		CONFIGURE_ARGS=		--enable-main
		CONFIGURE_ARGS+=	--with-main
		CONFIGURE_ARGS+=	--enable-sub1
		CONFIGURE_ARGS+=	--with-sub1
		CONFIGURE_ARGS+=	--enable-sub2
		CONFIGURE_ARGS+=	--with-sub2

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF
	create_file 'configure' <<-EOF
		enable_main
		with_main
	EOF
	create_file 'subdir1/configure' <<-EOF
		enable_sub1
	EOF
	create_file 'subdir2/configure' <<-EOF
		with_sub2
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '1'
	assert_that "$tmpdir/output" --file-is-lines \
		'error: [gnu-configure.mk] option --enable-sub2 not found in ./configure ./subdir1/configure ./subdir2/configure' \
		'error: [gnu-configure.mk] option --with-sub1 not found in ./configure ./subdir1/configure ./subdir2/configure' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin 'realistic example from gettext-tools-0.20.2 as of 2020-05-21'; then

	# Each of the subdirectories flags several options as unrecognized,
	# but in summary, each of the given options is used in at least one
	# subdirectory, which in this case is gettext-tools.

	create_file './configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_dependency_tracking
		enable_java
		enable_csharp
		enable_largefile
		enable_threads
		enable_shared
		enable_static
		with_pic
		enable_fast_install
		with_aix_soname
		with_gnu_ld
		with_sysroot
		enable_libtool_lock
		enable_nls
		enable_rpath
		with_libiconv_prefix
		enable_c__
		with_included_gettext
		with_libintl_prefix
		enable_cross_guesses
		enable_relocatable
		enable_libasprintf
		enable_curses
		with_libncurses_prefix
		with_libtermcap_prefix
		with_libxcurses_prefix
		with_libcurses_prefix
		enable_namespacing
		with_libtextstyle_prefix
		enable_openmp
		enable_acl
		with_included_libunistring
		with_libunistring_prefix
		with_included_libxml
		with_libxml2_prefix
		with_included_regex
		with_emacs
		with_lispdir
		with_git
		with_cvs
		with_bzip2
		with_xz
	EOF
	create_file './gettext-runtime/configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_dependency_tracking
		enable_java
		enable_csharp
		enable_largefile
		enable_threads
		enable_shared
		enable_static
		with_pic
		enable_fast_install
		with_aix_soname
		with_gnu_ld
		with_sysroot
		enable_libtool_lock
		enable_nls
		enable_rpath
		with_libiconv_prefix
		enable_c__
		with_included_gettext
		with_libintl_prefix
		enable_cross_guesses
		enable_relocatable
		enable_libasprintf
	EOF
	create_file './gettext-runtime/libasprintf/configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_dependency_tracking
		enable_shared
		enable_static
		with_pic
		enable_fast_install
		with_aix_soname
		with_gnu_ld
		with_sysroot
		enable_libtool_lock
		enable_cross_guesses
	EOF
	create_file './gettext-tools/configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_dependency_tracking
		enable_java
		enable_csharp
		enable_largefile
		enable_threads
		enable_shared
		enable_static
		with_pic
		enable_fast_install
		with_aix_soname
		with_gnu_ld
		with_sysroot
		enable_libtool_lock
		enable_nls
		enable_rpath
		with_libiconv_prefix
		enable_c__
		with_included_gettext
		with_libintl_prefix
		with_installed_libtextstyle
		with_libtextstyle_prefix
		with_installed_csharp_dll
		enable_openmp
		enable_cross_guesses
		enable_acl
		with_included_libunistring
		with_libunistring_prefix
		with_included_libxml
		with_libxml2_prefix
		enable_relocatable
		with_included_regex
		with_emacs
		with_lispdir
		with_git
		with_cvs
		with_bzip2
		with_xz
	EOF
	create_file './gettext-tools/examples/configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_nls
	EOF
	create_file './libtextstyle/configure' <<-EOF
		enable_option_checking
		enable_silent_rules
		enable_dependency_tracking
		enable_largefile
		enable_shared
		enable_static
		with_pic
		enable_fast_install
		with_aix_soname
		with_gnu_ld
		with_sysroot
		enable_libtool_lock
		enable_cross_guesses
		enable_rpath
		with_libiconv_prefix
		enable_curses
		with_libncurses_prefix
		with_libtermcap_prefix
		with_libxcurses_prefix
		with_libcurses_prefix
		enable_namespacing
	EOF

	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.
		CONFIGURE_ARGS+=	--disable-csharp
		CONFIGURE_ARGS+=	--disable-java
		CONFIGURE_ARGS+=	--with-included-libcroco
		CONFIGURE_ARGS+=	--without-git
		CONFIGURE_ARGS+=	--with-xz
		CONFIGURE_ARGS+=	--without-included-gettext
		CONFIGURE_ARGS+=	--without-emacs
		CONFIGURE_ARGS+=	--disable-openmp
		CONFIGURE_ARGS+=	--prefix=/home/pbulk/pkg
		CONFIGURE_ARGS+=	--build=x86_64--netbsd
		CONFIGURE_ARGS+=	--host=x86_64--netbsd
		CONFIGURE_ARGS+=	--infodir=/home/pbulk/pkg/info
		CONFIGURE_ARGS+=	--mandir=/home/pbulk/pkg/man

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	# There is one option that is unknown in all configure scripts.
	#
	# This was already reported by the implementation before May
	# 2020.  That check was expensive to run though, therefore it
	# had to be run manually.
	#
	# In May 2019, when GNU_CONFIGURE_STRICT=no was added to the
	# package, the check reported: "good: all 8 options are used
	# somewhere".  With the update to 0.20.2, the option had been
	# removed but the check was never run again.  This made the
	# check pretty useless since detecting outdated definitions was
	# its primary purpose.
	#
	# In May 2020, if the old check had been run, it reported:
	# "option --with-included-libcroco is unknown in all 6 configure
	# scripts".
	#
	# The May 2020 implementation of this check does not require
	# packages with multiple configure scripts to set this variable,
	# which immediately flags these outdated definitions instead of
	# hiding them just because it had worked some day in the past.
	# Furthermore, it is very cheap to run since it statically
	# analyzes the configure scripts instead of running them.
	#
	# This approach also has its drawbacks though.  It does not
	# detect cases in which only some of the configure scripts are
	# actually used for a build but the unknown option is defined in
	# one of the unused configure scripts.  This case happens less
	# often than a regular package update, therefore it is
	# acceptable.

	assert_that "$exitcode" --equals '1'
	assert_that "$tmpdir/output" --file-is-lines \
		'error: [gnu-configure.mk] option --with-included-libcroco not found in ./configure ./gettext-runtime/configure ./gettext-runtime/libasprintf/configure ./gettext-tools/configure ./gettext-tools/examples/configure ./libtextstyle/configure' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin 'configure script without enable_http variable'; then

	# textproc/opensp as of 2020-05-22 has a configure script
	# generated by Autoconf 2.59.  That configure script recognizes
	# --enable-http but does not have a corresponding variable
	# definition in a line of their own.
	#
	# The word --enable-http appears twice in that file.  Once in the
	# --help text, and once in a shell comment saying "Check whether
	# --enable-http or --disable-http was given".  The shell comment
	# is too unreliable, and the help text only contains either enable
	# or disable, but not both.  Therefore the simplest solution is to
	# scan for the common pattern ${enable_http+set}.

	# In lang/mono4, the option name "libgc" creatively differs from
	# the name "gc" that is mentioned in the help text:
	#
	# AC_ARG_WITH(libgc,
	#   [  --with-gc=...],
	#   [libgc=$with_gc],
	#   [libgc=$libgc_default]
	# )
	#
	# This way, even though --with-gc is documented in the help,
	# specifying it triggers the "unrecognized options: --with-gc"
	# warning 3 times, once for each configure script.

	create_file 'configure' <<-EOF
		if test "\${enable_http+set}" = set; then
			:
		fi
		if test "\${enable_nls+set}" = set; then
			:
		fi
	EOF
	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		.
		CONFIGURE_ARGS+=	--enable-http
		CONFIGURE_ARGS+=	--enable-nls

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF


	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-empty

	test_case_end
fi


if test_case_begin 'custom CONFIGURE_SCRIPT in relative directory'; then

	create_file 'pkgname-1.0/configure.gnu' <<-EOF
		if test "\${enable_option+set}" = set; then :; fi
	EOF
	mkdir 'build'
	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		build
		CONFIGURE_SCRIPT=	../pkgname-1.0/configure.gnu
		CONFIGURE_ARGS=		--enable-option

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-empty

	test_case_end
fi


if test_case_begin 'custom CONFIGURE_SCRIPT in absolute directory'; then

	create_file 'pkgname-1.0/configure.gnu' <<-EOF
		if test "\${enable_option+set}" = set; then :; fi
	EOF
	mkdir 'build'
	create_file 'testcase.mk' <<-EOF
		GNU_CONFIGURE_STRICT=	yes
		CONFIGURE_DIRS=		build
		CONFIGURE_SCRIPT=	\${WRKDIR}/pkgname-1.0/configure.gnu
		CONFIGURE_ARGS=		--enable-option

		.include "setup.mk"
		.include "mk/configure/gnu-configure.mk"
	EOF

	run_bmake 'testcase.mk' '_check-unknown-configure-options' \
		1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals '0'
	assert_that "$tmpdir/output" --file-is-empty

	test_case_end
fi

# $NetBSD: Makefile,v 1.7 2022/06/28 11:31:14 wiz Exp $

# XXX This is kludgerific copypasta of devel/libtool-base/Makefile for
# cross-compilation.  Please make it go away!

###########################################################################
###########################################################################
#
# HEADS UP!  DO NOT CHANGE THE VERSION OR PKGREVISION WITHOUT READING THIS:
#
###########################################################################
###########################################################################
#
# This package is maintained specially in order to preserve pkgsrc
# specific OS changes that diverge from the "out of the box" libtool.
# In order to keep this package in a maintainable condition, the .m4 files
# must be manipulated in order to generate the patch-* files.
#
# See devel/libtool/patches/manual.README for instructions on how to make
# these patch files properly; otherwise your changes WILL be lost on the
# next libtool update.
#
# DO NOT MAKE CHANGES TO THESE FILES:
#
#   patches/patch-build-aux_ltmain.sh
#   patches/patch-configure
#   patches/patch-libltdl_configure
#
# WITHOUT FOLLOWING THESE INSTRUCTIONS.  There are no exceptions to this rule.
#
###########################################################################
###########################################################################

LIBTOOL_CROSS_COMPILE=	yes

.include "../../devel/libtool/Makefile.common"

# XXX Tweaked for cross-compilation.
#PKGNAME=	${DISTNAME:S/-/-base-/}
PKGNAME=	${DISTNAME:S/^libtool-/cross-libtool-base-${MACHINE_ARCH}-/}
PKGREVISION=	8

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

TEST_TARGET=	check

OVERRIDE_DIRDEPTH.install-sh=	1

# Always build libraries and executables that use the runtime linker.
# in addition, disable libtool locking, as the test is broken on AIX,
# and results in files being locked indefinitely.
LDFLAGS.AIX+=		-Wl,-brtl
CONFIGURE_ARGS.AIX+=	--disable-libtool-lock

# The MIPSpro compiler doesn't support -c with -o, but the locking
# workaround is itself broken.  Disable it unconditionally.
CONFIGURE_ARGS.IRIX+=	--disable-libtool-lock

CFLAGS.SunOS+=	${_COMPILER_ABI_FLAG.${ABI}}

# We are going to want libtool to find the same versions of the C, C++,
# and Fortran compilers.
#
USE_LANGUAGES=		c c++
# XXX Added for cross-compilation.  XXX Should be ${TARGET_ARCH}, but
# currently we have to fake-cross-compile libtool because it's broken
# upstream.
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross-${MACHINE_ARCH}
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	F77=no FC=no

USE_TOOLS+=		echo

# XXX Added for cross-compilation.
FILESDIR=	../../devel/libtool-base/files

.PHONY: fix-libtool
fix-libtool:
	cd ${WRKSRC}; for f in libtool; do				\
		${SED}	-e "s,-L${BUILDLINK_DIR}/lib *,,g"		\
			-e "s,${BUILDLINK_DIR}/lib *,,g"		\
			$$f > $$f.new;					\
		if [ -x $$f ]; then ${CHMOD} +x $$f.new; fi;		\
		${MV} -f $$f.new $$f;					\
	done

post-build: fix-libtool

post-build:
	@${SED}	-e "s|@PREFIX@|"${PREFIX:Q}"|g"				\
		-e "s|@SH@|"${SH:Q}"|g"					\
		${FILESDIR}/shlibtool.in > ${WRKSRC}/shlibtool

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shlibtool ${DESTDIR}${PREFIX}/cross-${MACHINE_ARCH}/bin/shlibtool

BUILDLINK_DEPMETHOD.dlcompat=	build

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

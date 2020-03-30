# $NetBSD: Makefile,v 1.7 2020/03/30 19:36:03 joerg Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-8.0.2-src
PKGNAME=	${DISTNAME:S/-src$//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://downloads.haskell.org/~ghc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell - 8.0 Release Series
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	datasize virtualsize

# TODO: We should be using the alternatives framework.
CONFLICTS+=	ghc-[0-9]*

# GHC requires GHC to build itself. Formerly we could work around this
# bootstrapping problem by creating a special archive containing C
# sources compiled from Haskell sources, but that's no longer
# possible. So we have to prepare stripped-down binaries sufficient to
# bootstrap compilers for each platforms. If you want to build them
# yourself, follow instructions in BOOTSTRAP.txt and ./bootstrap.mk
#BROKEN_EXCEPT_ON_PLATFORM+= Darwin-*-powerpc # Not available yet
BROKEN_EXCEPT_ON_PLATFORM+= FreeBSD-*-i386
BROKEN_EXCEPT_ON_PLATFORM+= FreeBSD-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+= NetBSD-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+= SunOS-*-x86_64


# -----------------------------------------------------------------------------
# Distfiles
#
DISTFILES=	${DEFAULT_DISTFILES}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DEFAULT_DISTFILES}


# -----------------------------------------------------------------------------
# Tools
#
# The runtime dependency on perl is due to the evil splitter
# (lib/${PKGNAME_NOREV}/ghc-split).
USE_TOOLS+=			autoconf gmake gzip perl:run
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=		no
USE_LIBTOOL=			yes

CONFIGURE_ARGS.common= \
	--with-gcc=${CC:Q} \
	--with-ld=${LD:Q} \
	--with-curses-libraries=${BUILDLINK_PREFIX.curses:Q}/${BUILDLINK_LIBDIRS.curses:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp:Q}/${BUILDLINK_INCDIRS.gmp:Q} \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp:Q}/${BUILDLINK_LIBDIRS.gmp:Q} \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv:Q}/${BUILDLINK_INCDIRS.iconv:Q} \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv:Q}/${BUILDLINK_LIBDIRS.iconv:Q} \
	--with-system-libffi \
	--with-ffi-includes=${BUILDLINK_PREFIX.libffi:Q}/${BUILDLINK_INCDIRS.libffi:Q} \
	--with-ffi-libraries=${BUILDLINK_PREFIX.libffi:Q}/${BUILDLINK_LIBDIRS.libffi:Q}

CONFIGURE_ARGS+= ${CONFIGURE_ARGS.common}

CONFIGURE_ENV+= \
	ac_cv_path_fp_prog_ar=${AR:Q} \
	PerlCmd=${PERL5:Q}

# LDFLAGS is currently not honored by "./configure". Since LDFLAGS
# contains rpath flags it's very important to force GHC to honor
# it. Otherwise neither GHC itself nor executables it produces will
# have any rpaths so users will have to put "${PREFIX}/lib" into their
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
.for stage in 0 1 2
CONFIGURE_ENV+= \
	CONF_GCC_LINKER_OPTS_STAGE${stage}=${LDFLAGS:Q}
# Note that CONF_LD_LINKER_OPTS_STAGE{0,1,2} are only used for
# creating static GHCi libraries (HS*.o). Setting them to ${LDFLAGS}
# does more harm than good because our ${LDFLAGS} contains -Wl,*
# flags. It's true that ../../mk/wrapper/cmd-sink-ld transforms them
# but those flags will also be baked into the compiler (see
# ${WRKSRC}/compiler/ghc.mk) so they cause problems when used outside
# the buildlink.
.endfor

# The runtime system of GHC (rts) tends to conflict with PaX MPROTECT
# because it needs to generate various kinds of code at run time. The
# RTS linker, whose job is to load *static* objects at run time,
# doesn't play nice with ASLR either. This means most executables
# produced by GHC need them to be disabled. Perhaps we should patch
# rts/sm/Storage.c so that it uses ffi_closure_alloc(3) on every
# platform, not just Linux, and also drop support for static library
# loading and switch to dynamic libraries entirely.
.for f in ghc ghc-iserv ghc-iserv-dyn ghc-iserv-prof ghc-pkg haddock hpc hsc2hs runghc
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGNAME_NOREV}/bin/${f}
NOT_PAX_ASLR_SAFE+=	lib/${PKGNAME_NOREV}/bin/${f}
.endfor


# -----------------------------------------------------------------------------
# Build hooks
#

# We patch configure.ac in some directories.
post-patch:
	@${PHASE_MSG} "Regenerating configuration scripts for ${PKGNAME}"
	${RUN} cd ${WRKSRC:Q}                       && autoconf
	${RUN} cd ${WRKSRC:Q}/libraries/base        && autoconf
	${RUN} cd ${WRKSRC:Q}/libraries/integer-gmp && autoconf

# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../lang/ghc80/bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.

# Here we generate mk/build.mk dynamically.
post-configure:
	${RUN} ${RM} -f ${WRKSRC:Q}/mk/build.mk

# If there is HsColour in the PATH, GHC's build system tries to use it
# without even checking if it really works. That's not what we
# appreciate.
	${RUN} ${ECHO} "HSCOLOUR_SRCS    = NO" >> ${WRKSRC:Q}/mk/build.mk

# Don't even think of PDF.
	${RUN} ${ECHO} "BUILD_SPHINX_PDF = NO" >> ${WRKSRC:Q}/mk/build.mk


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	GHC_VERSION=${PKGVERSION_NOREV}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/lib/${PKGNAME_NOREV}/package.conf.d/package.cache


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs files with a
# hashed name. And "PLIST_TYPE = dynamic" appears to be broken atm
# [2019-12-27; pho].
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};


# -----------------------------------------------------------------------------
# Sanity checks
#

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# Dynamically linked Haskell executables and libraries have rpaths to
# dependent Haskell libraries, but the problem is that they are
# specified with $ORIGIN, which isn't currently supported by
# ../../mk/check/check-shlibs-elf.awk.
CHECK_SHLIBS_SKIP+=		*/libHS*-ghc${PKGVERSION_NOREV}.*
.for f in ghc ghc-iserv-dyn ghc-pkg haddock hpc hsc2hs runghc
CHECK_SHLIBS_SKIP+=		lib/${PKGNAME_NOREV}/bin/${f}
.endfor

# ghc57207_0.s: failed to add inputs for merge: Resource temporarily unavailable
CTF_FILES_SKIP+=		*/libHS*-ghc${PKGVERSION_NOREV}.*

# ld: fatal: relocation error ... relocation requires reference symbol
STRIP_FILES_SKIP+=		lib/${PKGNAME_NOREV}/libHSrts.a


# -----------------------------------------------------------------------------
# Dependencies
#
BUILDLINK_DEPMETHOD.python:=	build
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

# NetBSD 9.x have libcurses with a newer major version than the
# bootstrap kit is linked against. For now, work around this with
# compat80.
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
BUILD_DEPENDS+=	compat80-[0-9]*:../../emulators/compat80
# In a sandboxed build environment, we have to reach over to the
# installed libraries themselves, since the symlinks compat80 adds
# to the /usr tree can't be applied.
ALL_ENV+=	LD_LIBRARY_PATH=${PREFIX:Q}/emul/netbsd/usr/lib:${FILESDIR}
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

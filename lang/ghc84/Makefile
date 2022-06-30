# $NetBSD: Makefile,v 1.20 2022/06/30 11:18:32 nia Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-8.4.4-src
PKGNAME=	${DISTNAME:S/-src$//}
PKGREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	https://downloads.haskell.org/~ghc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell - 8.4 Release Series
LICENSE=	modified-bsd

MKPIE_SUPPORTED=	no

UNLIMIT_RESOURCES=	datasize virtualsize

# GHC requires GHC to build itself. We have to prepare stripped-down
# binaries sufficient to bootstrap compilers for each platforms. If
# you want to build them yourself, follow instructions in
# BOOTSTRAP.txt and ./bootstrap.mk
#BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-powerpc # Not available yet
BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	FreeBSD-*-i386
BROKEN_EXCEPT_ON_PLATFORM+=	FreeBSD-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	NetBSD-*-x86_64
#BROKEN_EXCEPT_ON_PLATFORM+=	SunOS-*-i386     # Not available yet
BROKEN_EXCEPT_ON_PLATFORM+=	SunOS-*-x86_64


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
USE_TOOLS+=			autoconf gmake perl:run
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=		no
USE_LIBTOOL=			yes

CONFIGURE_ARGS.common= \
	--with-curses-libraries=${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_INCDIRS.gmp:Q} \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_LIBDIRS.gmp:Q} \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_INCDIRS.iconv:Q} \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_LIBDIRS.iconv:Q} \
	--with-system-libffi \
	--with-ffi-includes=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_INCDIRS.libffi:Q} \
	--with-ffi-libraries=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_LIBDIRS.libffi:Q}

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.common}

# We must pass non-wrapper tools to ./configure because they will be
# embedded in the compiler (actually ${WRKSRC}/settings).
CONFIGURE_ENV+= \
	ac_cv_prog_fp_prog_ar=${AR:Q} \
	ac_cv_prog_LIBTOOL=libtool \
	PerlCmd=${PERL5:Q} \
	CC=${CC:Q} \
	LD=${LD:Q}

# LDFLAGS is currently not honored by "./configure". Since LDFLAGS
# contains rpath flags it's very important to force GHC to honor
# it. Otherwise neither GHC itself nor executables it produces will
# have any rpaths so users will have to put "${PREFIX}/lib" into their
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
.for stage in 0 1 2
CONFIGURE_ENV+= \
	CONF_GCC_LINKER_OPTS_STAGE${stage}=${LDFLAGS:M*:Q}
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
	${RUN} cd ${WRKSRC} && autoconf

# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../lang/ghc84/bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.

# The version restriction on Sphinx in ${WRKSRC}/configure.ac is too
# loose, and building docs/users_guide rarely succeeds. We don't know
# which version is actually required for it.
.include "../../mk/bsd.prefs.mk"
BUILD_SPHINX_HTML?=	no

# Here we generate mk/build.mk dynamically.
post-configure:
	${RUN} ${RM} -f ${WRKSRC}/mk/build.mk

# If there is HsColour in the PATH, GHC's build system tries to use it
# without even checking if it really works. That's not what we
# appreciate.
	${RUN} ${ECHO} "HSCOLOUR_SRCS     = NO" >> ${WRKSRC}/mk/build.mk

.if ${BUILD_SPHINX_HTML} == "no"
	${RUN} ${ECHO} "BUILD_SPHINX_HTML = NO" >> ${WRKSRC}/mk/build.mk
.endif

# Don't even think of PDF.
	${RUN} ${ECHO} "BUILD_SPHINX_PDF  = NO" >> ${WRKSRC}/mk/build.mk

# https://gitlab.haskell.org/ghc/ghc/issues/13542
.if ${OPSYS} == "SunOS"
	${RUN} ${ECHO} "SplitSections     = YES" >> ${WRKSRC}/mk/build.mk
.endif


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	GHC_VERSION=${PKGVERSION_NOREV}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/package.conf.d/package.cache


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs files with a
# hashed name. And "PLIST_TYPE = dynamic" appears to be broken atm
# [2019-12-27; pho].
GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};


# -----------------------------------------------------------------------------
# Sanity checks
#

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# ghc57207_0.s: failed to add inputs for merge: Resource temporarily unavailable
CTF_FILES_SKIP+=		*/libHS*-ghc${PKGVERSION_NOREV}.*

# ld: fatal: relocation error ... relocation requires reference symbol
STRIP_FILES_SKIP+=		lib/${PKGNAME_NOREV}/libHSrts.a


# -----------------------------------------------------------------------------
# Dependencies
#
.if ${BUILD_SPHINX_HTML} != "no"
BUILDLINK_DEPMETHOD.python:=	build
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

# NetBSD 9.x have libcurses with a newer major version than the
# bootstrap kit is linked against. For now, work around this with
# compat80.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 090000
BUILD_DEPENDS+=	compat80-[0-9]*:../../emulators/compat80
# In a sandboxed build environment, we have to reach over to the
# installed libraries themselves, since the symlinks compat80 adds
# to the /usr tree can't be applied.
ALL_ENV+=	LD_LIBRARY_PATH=${PREFIX}/emul/netbsd/usr/lib:${WRKDIR}/lib
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

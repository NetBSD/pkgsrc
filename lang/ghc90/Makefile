# $NetBSD: Makefile,v 1.21 2022/06/30 11:18:33 nia Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-9.0.2-src
PKGREVISION=	2
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	lang
MASTER_SITES=	https://downloads.haskell.org/~ghc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell - 9.0 Release Series
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	datasize virtualsize

# GHC requires GHC to build itself. We have to prepare stripped-down
# binaries sufficient to bootstrap compilers for each platform. If
# you want to build them yourself, follow instructions in
# BOOTSTRAP.txt and ./bootstrap.mk
BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	FreeBSD-*-i386
BROKEN_EXCEPT_ON_PLATFORM+=	FreeBSD-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	NetBSD-*-aarch64
BROKEN_EXCEPT_ON_PLATFORM+=	NetBSD-*-x86_64
BROKEN_EXCEPT_ON_PLATFORM+=	SunOS-*-x86_64

# We are going to do a PIE build on our responsibility. Do not put -pie in
# wrappers, as that would prevent us from building stage-1 compiler.
PKGSRC_OVERRIDE_MKPIE=	yes

.include "options.mk"


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
USE_TOOLS+=			autoconf gmake
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=		no
USE_LIBTOOL=			yes


# -----------------------------------------------------------------------------
# Configuration
#
CONFIGURE_ARGS.common+= \
	--with-curses-libraries=${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_INCDIRS.gmp:Q} \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_LIBDIRS.gmp:Q} \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_INCDIRS.iconv:Q} \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_LIBDIRS.iconv:Q} \
	--with-ffi-includes=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_INCDIRS.libffi:Q} \
	--with-ffi-libraries=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_LIBDIRS.libffi:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# The GHC rts, by default, creates executable objects on the heap by first
# mmap(2)'ing an anonymous memory with PROT_READ|PROT_WRITE and then calling
# mprotect(2) with PROT_READ|PROT_EXEC after filling its content. However,
# NetBSD PaX mprotect doesn't allow this practice. That is, turning pages that
# have been initially mapped as non-executable into something executable is a
# no-no. We must therefore take a different path although it might be a bit slower.
CONFIGURE_ARGS.common+=	--enable-libffi-adjustors
# See rts/adjustor/NativeAmd64.c and rts/adjustor/LibffiAdjustor.c
.endif

# We must pass non-wrapper tools to ./configure because they will be
# embedded in the compiler (actually ${WRKSRC}/settings).
CONFIGURE_ENV+=		ac_cv_prog_fp_prog_ar=${AR:Q}
CONFIGURE_ENV+=		ac_cv_prog_LIBTOOL=libtool
CONFIGURE_ARGS.common+=	LD=${LD:Q}

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.common}
CONFIGURE_ARGS+=	--with-system-libffi

# CFLAGS and LDFLAGS are currently not honored by "./configure". Since
# LDFLAGS contains rpath flags it's very important to force GHC to honor
# it. Otherwise neither GHC itself nor executables it produces will have
# any rpaths so users will have to put "${PREFIX}/lib" into their
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
.for stage in 0 1 2
CONFIGURE_ENV+=	CONF_GCC_LINKER_OPTS_STAGE${stage}=${LDFLAGS:M*:Q}
# Note that CONF_LD_LINKER_OPTS_STAGE{0,1,2} are only used for
# creating static GHCi libraries (HS*.o). Setting them to ${LDFLAGS}
# does more harm than good because our ${LDFLAGS} contains -Wl,*
# flags. It's true that ../../mk/wrapper/cmd-sink-ld transforms them
# but those flags will also be baked into the compiler (see
# ${WRKSRC}/compiler/ghc.mk) so they cause problems when used outside
# the buildlink.
.endfor

# The use of internal variable ${_PKGSRC_MKPIE} in mk/bsd.prefs.mk is not
# very satisfying, but the current infrastructure does not export a public
# variable indicating whether a PIE build is requested or not. Note that we
# can't build stage-1 compiler as PIE, because our bootkit libraries aren't
# necessarily built as PIC.
.for stage in 0 1 2
.  if ${stage} == 0
CONFIGURE_ENV+=	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}
.  else
.    if ${_PKGSRC_MKPIE} == "yes"
CONFIGURE_ENV+=	CONF_HC_OPTS_STAGE${stage}=-fPIC\ -pie
CONFIGURE_ENV+=	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}\ -fPIC
.    else
CONFIGURE_ENV+=	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}
.    endif
.  endif
.endfor


# -----------------------------------------------------------------------------
# Security
#
# The runtime system of GHC (rts) has a functionality called "RTS linker"
# whose job is to load and execute *static* objects (.a and .o files) at
# run time. It cannot survive PaX MPROTECT because preloadObjectFile() in
# rts/linker.c tries to mmap pages with w+x. It doesn't play nice with ASLR
# either because mmapForLinker() in rts/linker.c wants to always mmap pages
# in the lower 32-bit area on 64-bit platforms.
#
# Luckily for us, the RTS linker is only used when the GHC executable (or
# any user programs which uses GHC API as an interpreter, not a compiler)
# is statically linked, which is no longer the case except for ghc-iserv
# and ghc-iesrv-prof. They are launched when ghci is started with
# -fexternal-interpreter without -dynamic, and their purpose is to run
# non-PIC code from a dynamically linked ghci using the evil RTS linker.
.for f in ghc-iserv ghc-iserv-prof
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
.include "../../lang/ghc90/bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.

# The version restriction on Sphinx in ${WRKSRC}/configure.ac is too
# loose, and building docs/users_guide rarely succeeds. We don't know
# which version is actually required for it.
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

# SplitSections is only enabled by default on platforms with GNU ld. On SunOS,
# whose ld is not the GNU one, it can however be used as well.
.if ${OPSYS} == "SunOS"
	${RUN} ${ECHO} "SplitSections  = YES" >> ${WRKSRC}/mk/build.mk
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

# ghc57207_0.s: failed to add inputs for merge: Resource temporarily unavailable
# XXX: On which platform? Is it still an issue?
CTF_FILES_SKIP+=		*/libHS*-ghc${PKGVERSION_NOREV}.*

# ld: fatal: relocation error ... relocation requires reference symbol
# XXX: On which platform? Is it still an issue?
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
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) && ${OPSYS_VERSION} >= 090000
BUILD_DEPENDS+=	compat80-[0-9]*:../../emulators/compat80
# In a sandboxed build environment, we have to reach over to the
# installed libraries themselves, since the symlinks compat80 adds
# to the /usr tree can't be applied.
ALL_ENV+=	LD_LIBRARY_PATH=${PREFIX}/emul/netbsd/usr/lib:${WRKDIR}/lib
# XXX: ${WRKDIR}/lib is a temporary workaround for compat80 not having
# libterminfo.so.1. See ./bootstrap.mk
.endif

# On Solaris-based platforms our bootkit tends to depend on
# pkgsrc-installed shlibs.
.if ${OPSYS} == "SunOS"
ALL_ENV+=	LD_LIBRARY_PATH=${PREFIX}/lib
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

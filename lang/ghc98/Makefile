# $NetBSD: Makefile,v 1.4 2024/05/11 18:37:40 pho Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-9.8.2-src
PKGNAME=	${DISTNAME:S/-src$//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://downloads.haskell.org/~ghc/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell - 9.8 Release Series
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	cputime datasize virtualsize

# GHC requires GHC to build itself. We have to prepare stripped-down
# binaries sufficient to bootstrap compilers for each platform. If you want
# to build them yourself, follow instructions in files/BOOTSTRAP.md.
BROKEN_EXCEPT_ON_PLATFORM+=	Darwin-*-aarch64
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
USE_LANGUAGES+=			c c++
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=		no
USE_LIBTOOL=			yes
PYTHON_FOR_BUILD_ONLY=		tool
.include "../../lang/python/tool.mk"


# -----------------------------------------------------------------------------
# Configuration
#
HADRIAN_ARGS.common=	# empty
HADRIAN_ARGS.common+=	-j${_MAKE_JOBS_N}
HADRIAN_ARGS=		${HADRIAN_ARGS.common}

# The output from Hadrian is too terse by default. Use at least a single
# --verbose so we can know what's really going on.
HADRIAN_ARGS.common+=	--verbose ${PKG_VERBOSE:D--verbose}

CONFIGURE_ARGS.common+= \
	--with-curses-libraries=${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_INCDIRS.gmp:Q} \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_LIBDIRS.gmp:Q} \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_INCDIRS.iconv:Q} \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_LIBDIRS.iconv:Q} \
	--with-ffi-includes=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_INCDIRS.libffi:Q} \
	--with-ffi-libraries=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_LIBDIRS.libffi:Q}

.include "../../mk/bsd.prefs.mk"

# We must pass non-wrapper tools to ./configure because they will be
# embedded in the compiler (actually ${WRKSRC}/settings).
CONFIGURE_ENV+=		ac_cv_prog_fp_prog_ar=${AR:Q}
CONFIGURE_ENV+=		ac_cv_prog_LIBTOOL=libtool
CONFIGURE_ARGS.common+=	LD=${LD:Q}

# While we use binutils ar which supports "@", this appears to be leaking
# somewhere into assuming that SunOS ld also supports "@" which it does not.
CONFIGURE_ENV.SunOS+=	fp_cv_prog_ar_supports_atfile=no

# If there is HsColour in the PATH, GHC's build system tries to use it
# without checking if it really works. That's not what we appreciate.
CONFIGURE_ENV+=		ac_cv_path_HSCOLOUR=

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
CONFIGURE_ENV+=	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}\ -fPIC
CONFIGURE_ENV+=	CONF_HC_OPTS_STAGE${stage}=-fPIC\ -pie
# Hadrian doesn't honor CONF_HC_OPTS_STAGE${stage}. Possibly a bug?
HADRIAN_ARGS+=	"stage${stage}.*.ghc.c.opts += -fPIC"
HADRIAN_ARGS+=	"stage${stage}.*.ghc.hs.opts += -fPIC"
HADRIAN_ARGS+=	"stage${stage}.*.ghc.link.opts += -pie"
.    else
CONFIGURE_ENV+=	CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}
.    endif
.  endif
.endfor
.if ${_PKGSRC_MKPIE} == "yes"
# utils/unlit is a special case. It's built with the stage-0 compiler but
# since it's entirely written in C there's no problem doing a PIE build.
HADRIAN_ARGS+=	"*.unlit.ghc.c.opts += -fPIC"
HADRIAN_ARGS+=	"*.unlit.ghc.link.opts += -pie"
.endif

# MacOS X 10.7 is the oldest OS X version supporting __thread. Although
# ${WRKSRC}/configure has a check for it, the actual build will fail
# without this env.
.if ${OPSYS} == "Darwin"
ALL_ENV+=	MACOSX_DEPLOYMENT_TARGET="10.7"
.endif


# -----------------------------------------------------------------------------
# Security
#
# The runtime system of GHC (rts) has a mechanism called "RTS linker" whose
# job is to load and execute *static* objects (.a and .o files) at run
# time. It cannot survive PaX MPROTECT because preloadObjectFile() in
# rts/linker.c tries to mmap pages with w+x. It doesn't play nice with ASLR
# either because mmapForLinker() in rts/linker.c wants to always mmap pages
# in the lower 32-bit area on 64-bit platforms.
#
# Luckily for us, the RTS linker is only used when the GHC executable (or
# any user programs which uses GHC API as an interpreter, not a compiler)
# is statically linked, which is no longer the case except for ghc-iserv
# and ghc-iesrv-prof. They are launched when ghci is started with
# -fexternal-interpreter without -dynamic, and their purpose is to run
# non-PIC code from within a dynamically linked ghci using the evil RTS
# linker.
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
	${RUN}cd ${WRKSRC} && autoconf
	${RUN}cd ${WRKSRC}/libraries/terminfo && autoconf

# Define the target "pre-configure", "pre-build", and non-standard
# "bootstrap".
.include "bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it. Our pre-build
# phase bootstraps Hadrian.

# We have a patch to Hadrian so that it uses absolute RPATHs as opposed to
# relative ones (i.e. $ORIGIN). The patch uses --prefix at build time.
HADRIAN_ARGS+=	--prefix=${PREFIX:Q}

# The version restriction on Sphinx in ${WRKSRC}/configure.ac is too
# loose, and building docs/users_guide rarely succeeds. We don't know
# which version is actually required for it.
BUILD_SPHINX_HTML?=	no
HADRIAN_ARGS+=		${${BUILD_SPHINX_HTML:tl} == "no":?--docs=no-sphinx:}

# Don't even think of PDF.
HADRIAN_ARGS+=		--docs=no-sphinx-pdfs

# Enable -fsplit-sections on platforms that support it.
.if ${OPSYS} == "FreeBSD"
#   -fsplit-sections appears to corrupt the symbol table of stage 1
#   libHSghc-*.a(Instances.o) and cause a linkage failure. Either Clang or
#   LLD is doing something wrong, probably the former.
HADRIAN_ARGS+=		--flavour=default
.else
HADRIAN_ARGS+=		--flavour=default+split_sections
.endif

do-build:
	${RUN}cd ${WRKSRC} && ${HADRIAN_CMD} ${HADRIAN_ARGS}
	${RUN}cd ${WRKSRC} && ${HADRIAN_CMD} ${HADRIAN_ARGS} docs


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}
FILES_SUBST+=	RM=${RM:Q}
FILES_SUBST+=	RMDIR=${RMDIR:Q}
FILES_SUBST+=	TRUE=${TRUE:Q}

# mk/install_script.sh, whose purpose is to generate GHC wrapper scripts to
# be installed, refers to the variable $SHELL. This is bad because our
# $SHELL is in the TOOLDIR.
SUBST_CLASSES+=			ghc-wrapper-sh
SUBST_STAGE.ghc-wrapper-sh=	post-extract
SUBST_FILES.ghc-wrapper-sh=	mk/install_script.sh
SUBST_SED.ghc-wrapper-sh=	-e 's,\#!\$$SHELL,\#!/bin/sh,'

# The "install" target in Hadrian doesn't support DESTDIR so we can't use
# it. We also need to give configure and "make install" some additional env
# vars and args.
do-install:
	${RUN}cd ${WRKSRC} && \
		${HADRIAN_CMD} ${HADRIAN_ARGS} binary-dist-dir
	${RUN}cd ${WRKSRC}/_build/bindist/ghc-* && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}
	${RUN}cd ${WRKSRC}/_build/bindist/ghc-* && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
			RECACHE_PACKAGE_DB=NO install

INSTALLATION_DIRS+=	share/bash-completion/completions
post-install:
	${INSTALL_DATA} ${WRKSRC}/utils/completion/ghc.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/ghc
# We don't want package.cache to be in the PLIST.
	for f in package.cache package.cache.lock; do \
		${RM} ${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/lib/package.conf.d/$$f; \
	done


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs files with a
# hashed name.
PLIST_TYPE=	dynamic


# -----------------------------------------------------------------------------
# Sanity checks
#

# These files don't pass our portability checks but we don't use them
# anyway.
CHECK_PORTABILITY_SKIP+=	validate

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
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

# NetBSD bootkits are currently built on 9. We need some compat libraries
# to run them on later versions.
#
# In a sandboxed build environment, we have to reach over to the
# installed libraries themselves, since the symlinks compatXX adds
# to the /usr tree can't be applied.
.if ${MACHINE_PLATFORM:MNetBSD-*-*} && ${OPSYS_VERSION} >= 099000
TOOL_DEPENDS+=	compat90-[0-9]*:../../emulators/compat90
ALL_ENV+=	LD_LIBRARY_PATH=${PREFIX}/emul/netbsd/usr/lib
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# ghc has UTF-8 issues, this is needed to avoid problems during build that
# may manifest from the bootstrap kit.  It comes after bsd.pkg.mk as that
# sets LC_ALL=C first.
#
# XXX I believe those issues have already been sorted out. If you still see
# issues please uncomment this and leave some explanation
# here so that I can look into. [2024-04-27; pho]
#ALL_ENV+=	LC_ALL=en_US.UTF-8

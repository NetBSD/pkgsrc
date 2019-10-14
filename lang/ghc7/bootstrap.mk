# $NetBSD: bootstrap.mk,v 1.25 2019/10/14 02:36:30 gutteridge Exp $
# -----------------------------------------------------------------------------
# Select a bindist of bootstrapping compiler on a per-platform basis.
#
# BOOT_ARCHIVE
#   This variable is set to the name of compressed archive file of a
#   bootstrapping compiler for the current platform.
#
# BOOT_TARBALL
#   Similar to BOOT_ARCHIVE, but "*.tar" not "*.tar.xz".
#
# BOOT_VERSION
#   Version of the bootstrapping compiler to use. This can be
#   overriden for specific platforms.
#
.include "../../mk/bsd.prefs.mk"

# Use the same version as the package itself by default.
BOOT_VERSION:=	${PKGNAME:C/^.*-//}

.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-powerpc-apple-darwin.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} # Available in LOCAL_PORTS
.endif

.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-i386-unknown-freebsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} # Available in LOCAL_PORTS
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-linux.tar.xz
#DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-i386-unknown-netbsd.tar.xz
#DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-netbsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} # Available in LOCAL_PORTS
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-i386) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-i386-unknown-solaris2.tar.xz
#DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE}
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-x86_64) || make(distinfo)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-solaris2.tar.xz
#DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE}
.endif

.if empty(BOOT_ARCHIVE)
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-unknown.tar.xz
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

# For package developers, please do not upload any bootkits unsafely
# built. That is, machines shared with someone or on a cloud hosting
# service should be avoided for building bootkits.
.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor

BOOT_TARBALL=	${BOOT_ARCHIVE:C/\.xz$//}

# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect for this platform. See ${WRKSRC}/aclocal.m4
# (FP_LEADING_UNDERSCORE)
.if ${OPSYS} == "Darwin"
CONFLICTS+=	libelf-[0-9]*
.endif

# FreeBSD < 10 surprisingly doesn't have a native iconv so we need to
# use pkgsrc libiconv for this OPSYS. And if a bootkit depends on
# pkgsrc libiconv, the "normal" build must do the same because GHC
# always needs to link executables with libiconv, just like libgmp
# when integer-gmp is used. For this reason it might be desirable to
# create two separate bootkits, one for < 10 and another for >= 10.
.if ${OPSYS} == "FreeBSD"
USE_BUILTIN.iconv=	no
.endif

# current bootstrap binary kit for SmartOS is built with ncurses5
.if !empty(MACHINE_PLATFORM:MSunOS-5.11-*) && !empty(OS_VARIANT:U:MSmartOS)
BUILD_DEPENDS+=	ncurses>=5.0:../../devel/ncurses
.endif


# -----------------------------------------------------------------------------
# The "pre-configure" hook
#
# Install a bootstrapping compiler directly into TOOLS_DIR so that
# ./configure can find it.
#
USE_TOOLS+=	gmake xzcat xz

pre-configure:
	@${TEST} -f ${DISTDIR:Q}/${DIST_SUBDIR:Q}/${BOOT_ARCHIVE} || \
	${FAIL_MSG}  "Put your trusted bootstrap archive as ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE}"

	@${PHASE_MSG} "Extracting bootstrapping compiler for ${PKGNAME}"
	${RUN} ${MKDIR} ${WRKDIR:Q}/build-extract
	${RUN} cd ${WRKDIR:Q}/build-extract && \
		${EXTRACT_CMD_DEFAULT} ${DISTDIR:Q}/${DIST_SUBDIR:Q}/${BOOT_ARCHIVE}

# It is important to install the stage-0 compiler with our rpath flags
# configured, otherwise it will produce executables with no rpath and
# fail in the configure phase.
	@${PHASE_MSG} "Preparing bootstrapping compiler for ${PKGNAME}"
	${RUN} cd ${WRKDIR:Q}/build-extract/${PKGNAME_NOREV}-boot && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure \
			--prefix=${TOOLS_DIR:Q} && \
		${MAKE_PROGRAM} install


# -----------------------------------------------------------------------------
# An unusual target "bootstrap"
#
# Build a bootstrapping compiler using an already installed GHC. This
# can certainly be impossible if you don't have one. It's absolutely
# important to build it with the fewest possible run-time
# dependencies, otherwise the resulting binary can easily get
# unusable.
#

# We don't want our bootkits to have a run-time dependency on
# libgcc. In fact GHC's implementation of Haskell exception handling
# does not depend on libgcc's facilities so it is attractive to do the
# same for "normal" build... but we can't. This is because Haskell
# programs may call C functions via FFI, and those C functions may
# call C++ functions in turn, possibly in a different shared library.
.include "../../mk/compiler.mk"
.if make(bootstrap) && !empty(CC_VERSION:Mgcc-*)
# But on some platforms, gcc automagically inserts a dependency on a
# shared libgcc when -lpthread is given, which is seemingly
# unavoidable.
LDFLAGS+=	-static-libgcc
.endif

# Gather information about packages on which bootkit depends. It will
# be used in the post-bootstrap phase.
BOOT_GHC_DEPS:=		curses iconv
BOOT_GHC_PKGSRC_DEPS:=	# empty
.for pkg in ${BOOT_GHC_DEPS}

# NOTE: pkglint(1) complains for including these builtin.mk files,
# telling that we must include buildlink3.mk instead. But then how do
# we get variables like USE_BUILTIN.${pkg} defined before including
# ../../mk/bsd.pkg.mk, given that ../../mk/bsd.buildlink3.mk isn't
# protected against multiple inclusion?
CHECK_BUILTIN.${pkg}:=	yes
.  if ${pkg} == "curses"
.    include "../../mk/curses.builtin.mk"
.  elif ${pkg} == "iconv"
.    include "../../converters/libiconv/builtin.mk"
.  endif
CHECK_BUILTIN.${pkg}:=	no

# BOOT_GHC_PKGSRC_DEPS is a list of packages whose pkgsrc version is
# preferred over native one, either by user or ../../mk/platform
.  if ${PREFER.${pkg}} == "pkgsrc"
BOOT_GHC_PKGSRC_DEPS+=	${pkg}
.  endif
.endfor

# Compiler wrappers must not remove -I/-L flags for the installed
# GHC's libdir, otherwise the GHC we are going to use for building our
# bootstraping kit will not work at all. Ideally it should be added to
# BUILDLINK_PASSTHRU_DIRS only .if make(bootstrap), but then running
# "${MAKE} wrapper" before "${MAKE} bootstrap" will result in a
# cryptic error which we can't easily catch.
BOOT_GHC_LIBDIR_CMD=		ghc --print-libdir
.if !defined(BOOT_GHC_LIBDIR)
BOOT_GHC_LIBDIR!=		(${BOOT_GHC_LIBDIR_CMD}) 2>/dev/null || ${ECHO}
.endif
MAKEVARS+=			BOOT_GHC_LIBDIR
BUILDLINK_PASSTHRU_DIRS+=	${BOOT_GHC_LIBDIR}

# Default values for BUILDLINK_INCDIRS.<pkg> are only generated in the
# barrier. See ../../mk/buildlink3/bsd.buildlink3.mk and
# ../../mk/bsd.pkg.barrier.mk
.PHONY: bootstrap
.if make(bootstrap)
_BARRIER_CMDLINE_TARGETS+=	bootstrap
.endif
.if !defined(_PKGSRC_BARRIER)
bootstrap: barrier
.else
bootstrap: pre-bootstrap .WAIT ${WRKDIR}/${BOOT_ARCHIVE} .WAIT post-bootstrap
.endif

.PHONY: pre-bootstrap
pre-bootstrap: wrapper
.if empty(BOOT_GHC_LIBDIR)
	@if ${BOOT_GHC_LIBDIR_CMD} 2>/dev/null 1>&2; then \
		${ERROR_MSG} "Running \"${BOOT_GHC_LIBDIR_CMD}\" has failed during wrapper phase."; \
		${FAIL_MSG}  "Please run \"${MAKE} clean\" and try again."; \
	else \
		${ERROR_MSG} "Failed to run \"${BOOT_GHC_LIBDIR_CMD}\":"; \
		${BOOT_GHC_LIBDIR_CMD}; \
		${ERROR_MSG} "You don't seem to have a working GHC in your PATH."; \
		${FAIL_MSG}  "Please install one and then run \"${MAKE} clean bootstrap\"."; \
	fi
.endif
# ${_COOKIE.configure} is not defined yet so we can't use .if here.
	@if ${TEST} -f ${_COOKIE.configure}; then \
		${ERROR_MSG} "You have already configured the package in a way\
		that building bootstrapping compiler is impossible."; \
		${FAIL_MSG}  "Please run \"${MAKE} clean\" first."; \
	fi

${WRKDIR}/lndir:
	@${PHASE_MSG} "Building lndir(1) to duplicate the source tree."
	cd ${WRKSRC:Q}/utils/lndir && \
		${PKG_CC:Q} lndir.c -o ${.TARGET}

${WRKDIR}/stamp-lndir-boot: ${WRKDIR}/lndir
	@${PHASE_MSG} "Duplicating the source tree for bootstrapping ${PKGNAME_NOREV}"
	${MKDIR} ${WRKDIR:Q}/build-boot
	cd ${WRKDIR:Q}/build-boot && \
		${WRKDIR}/lndir -silent ../${PKGNAME_NOREV:Q}
	${TOUCH} ${.TARGET}

# For terminfo_CONFIGURE_OPTS, see
# https://ghc.haskell.org/trac/ghc/ticket/10096
${WRKDIR}/stamp-configure-boot: ${WRKDIR}/stamp-lndir-boot
	@${PHASE_MSG} "Configuring bootstrapping compiler ${PKGNAME_NOREV}"
	${MKDIR} ${WRKDIR:Q}/build-boot
	cd ${WRKDIR:Q}/build-boot && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS} && \
		${CP} -f ${FILESDIR:Q}/bootstrap.build.mk mk/build.mk && \
		${ECHO} >> mk/build.mk && \
		${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
			--configure-option=--with-curses-includes=${BUILDLINK_PREFIX.curses:Q}/${BUILDLINK_INCDIRS.curses:Q} \
			--configure-option=--with-curses-libraries=${BUILDLINK_PREFIX.curses:Q}/${BUILDLINK_LIBDIRS.curses:Q}" \
			>> mk/build.mk
	${TOUCH} ${.TARGET}

${WRKDIR}/stamp-build-boot: ${WRKDIR}/stamp-configure-boot
	@${PHASE_MSG} "Building bootstrapping compiler ${PKGNAME_NOREV}"
	${RUN} cd ${WRKDIR:Q}/build-boot && ${BUILD_MAKE_CMD}
	${TOUCH} ${.TARGET}

${WRKDIR}/${BOOT_TARBALL}: ${WRKDIR}/stamp-build-boot
	@${PHASE_MSG} "Creating binary distribution of bootstrapping ${PKGNAME_NOREV}"
	${RUN} cd ${WRKDIR:Q}/build-boot && ${BUILD_MAKE_CMD} binary-dist
	${MV} -f ${WRKDIR:Q}/build-boot/${BOOT_TARBALL} ${.TARGET}

# This can take up half an hour. Memory usage is also very high, about 680 MiB.
${WRKDIR}/${BOOT_ARCHIVE}: ${WRKDIR}/${BOOT_TARBALL}
	@${PHASE_MSG} "Compressing binary distribution of bootstrapping ${PKGNAME_NOREV}"
	${XZ} --verbose -9 --extreme ${WRKDIR:Q}/${BOOT_TARBALL}

.PHONY: post-bootstrap
post-bootstrap:
	@${ECHO} "=========================================================================="
	@${ECHO} "Done creating ${BOOT_ARCHIVE}"
	@${ECHO} "  in ${WRKDIR}"
	@${ECHO}
	@${ECHO} "Now you can copy it into ${DISTDIR}/${DIST_SUBDIR} to use it as your"
	@${ECHO} "bootstrap kit. You may want to take a backup in case \"lintpkgsrc -r\""
	@${ECHO} "removes it."
	@${ECHO}
	@${ECHO} "Your bootstrap kit has the following run-time dependencies:"
.for pkg in ${BOOT_GHC_DEPS}
	@${PRINTF} "  * %-8s" "${pkg}:"
.  if !empty(USE_BUILTIN.${pkg}:M[nN][oO])
	@${ECHO_N} " pkgsrc ${BUILDLINK_PKGNAME.${pkg}}"
.  else
	@${ECHO_N} " native"
.    if empty(BUILTIN_PKG.${pkg})
	@${ECHO_N} " (version/variant unknown)"
.    else
	@${ECHO_N} " ${BUILTIN_PKG.${pkg}}"
.    endif
.  endif
	@${ECHO}
.endfor
.if !empty(BOOT_GHC_PKGSRC_DEPS)
	@${ECHO}
	@${ECHO} "Please note that it is generally not a good idea for a bootkit to depend"
	@${ECHO} "on pkgsrc packages, as pkgsrc tends to move faster than operating systems"
	@${ECHO} "so your bootkit may bitrot more quickly. You may want to rebuild it"
	@${ECHO} "without setting PREFER_PKGSRC to \"yes\"."
.endif
	@${ECHO} "=========================================================================="

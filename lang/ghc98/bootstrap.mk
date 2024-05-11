# $NetBSD: bootstrap.mk,v 1.4 2024/05/11 18:37:40 pho Exp $
# -----------------------------------------------------------------------------
# Select a bindist of bootstrapping compiler on a per-platform basis. See
# ./files/BOOTSTRAP.md for details.
#
# BOOT_ARCHIVE
#   This variable is set to the name of compressed archive file of a
#   bootstrapping compiler for the platform.
#
# BOOT_VERSION
#   Version of the bootstrapping compiler to use.
#
.include "../../mk/bsd.prefs.mk"

# Notes on version dependencies:
# * GHC 9.8.2 requires 9.4 or later to bootstrap.
# * GHC 9.6.3 requires 9.2 or later to bootstrap.
# * GHC 9.4.4 requires 9.0 or later to bootstrap.
# * GHC 9.2.1 requires 8.10 or later to bootstrap.
# * GHC 9.0.1 requires 8.8 or later to bootstrap.
# * GHC 8.8.4 requires 8.4 or later to bootstrap.
# * GHC 8.4.4 requires 8.0 or later to bootstrap.
# * GHC 8.0.2 requires 7.8 or later to bootstrap.
# * GHC 7.10.3 requires 7.6 or later to bootstrap.

# GHC has migrated away from GNU Make to Hadrian as its build system. We
# first need to build it in order to build GHC, but a source tarball
# required for building Hadrian is specific to the version of GHC to use
# for bootstrapping. See ./files/BOOTSTRAP.md for instructions on how to
# create one.
#HADRIAN_BOOT_SOURCE=	ghc-${BOOT_VERSION}-boot-hadrian-${PKGPATH:T}.tar.gz
HADRIAN_BOOT_SOURCE=	ghc-${BOOT_VERSION}-boot-hadrian-ghc9.8.tar.gz
# NOTE: CDN cached a wrong file due to my mistake. On the next major
# version uncomment the first definition and remove the second
# one. [2024-04-27; pho]

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-aarch64-apple-darwin.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-apple-darwin.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MFreeBSD-*-i386} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-i386-unknown-freebsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-freebsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
# Cross-compiled from x86_64 on a QEMU guest. It took days to compile...
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-aarch64-unknown-netbsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
BOOT_VERSION:=	9.4.7
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-netbsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=		9.4.7
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-x86_64-unknown-solaris2.tar.xz
SITES.${BOOT_ARCHIVE}=	https://us-central.manta.mnx.io/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

# DISTFILES contains duplicate HADRIAN_BOOT_SOURCE entries at this
# point. Dedupe them now.
DISTFILES:=	${DISTFILES:O:u}

.if empty(BOOT_ARCHIVE)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-unknown.tar.xz
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

# For package developers, please do not upload any bootkits unsafely
# built. That is, machines shared with someone or on a cloud hosting
# service should be avoided for building bootkits.
.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor

.if ${OPSYS} == "SunOS" && ${OS_VARIANT:U} == "OmniOS"
# On this platform cpp(1) is missing from /usr/bin. Why? This leads
# ${WRKSRC}/libffi/configure to fail.
TOOLS_PLATFORM.cpp=	/usr/lib/cpp
.endif


# -----------------------------------------------------------------------------
# The "pre-configure" hook
#
# Install a bootstrapping (stage-0) compiler directly into TOOLS_DIR so
# that ./configure can find it.
#
USE_TOOLS+=	xzcat xz gtar cpp patch # patch is for bootstrap.py

BOOT_ARCHIVE_TOP_DIR=	${BOOT_ARCHIVE:C/\.tar\..z$//}
pre-configure:
	${RUN}${TEST} -f ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE} || \
	${FAIL_MSG}  "Place your trusted bootkit archive at ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE}"

	@${PHASE_MSG} "Extracting bootstrapping compiler for ${PKGNAME}"
	${RUN}${MKDIR} ${WRKDIR}/bootkit-dist
	${RUN}cd ${WRKDIR}/bootkit-dist && \
		${XZCAT} ${DISTDIR}/${DIST_SUBDIR}/${BOOT_ARCHIVE} | \
		${GTAR} -xf -

	@${PHASE_MSG} "Preparing bootstrapping compiler for ${PKGNAME}"
# <kludge>
# "RTS ways" in "ghc --info" is totally bogus, because GhcRTSWays in
# hadrian/bindist/config.mk.in does not reflect Hadrian user settings at
# all. This leads Hadrian to believe that the stage-0 compiler has threaded
# RTS even if it doesn't. Note that GHC devs are in the process of moving
# the settings file from being generated by configure, to being generated
# by the build system. This workaround is expected to go away in the
# (hopefully near) future.
	${RUN}cd ${WRKDIR}/bootkit-dist/${BOOT_ARCHIVE_TOP_DIR} && \
		${SED} -e '/^GhcRTSWays/d' < mk/config.mk.in > mk/config.mk.in.tmp && \
		${MV} -f mk/config.mk.in.tmp mk/config.mk.in
# </kludge>
	${RUN}cd ${WRKDIR}/bootkit-dist/${BOOT_ARCHIVE_TOP_DIR} && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure \
			--prefix=${TOOLS_DIR:Q} ${CONFIGURE_ARGS.boot} && \
		${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install


# -----------------------------------------------------------------------------
# The "pre-build" hook
#
# Bootstrap Hadrian with the stage-0 compiler. It is important to do this
# in "pre-build" because we often need to patch Hadrian itself while
# updating our packages and we want it to be rebuilt every time we make
# changes to it.
#
pre-build:
	${RUN}${TEST} -f ${DISTDIR}/${DIST_SUBDIR}/${HADRIAN_BOOT_SOURCE} || \
		${FAIL_MSG} "${HADRIAN_BOOT_SOURCE} not found in ${DISTDIR}/${DIST_SUBDIR}.\
			You first need to create it before building ${PKGNAME}.\
			See ./files/BOOTSTRAP.md for details."

	@${PHASE_MSG} "Building Hadrian for GHC ${BOOT_VERSION}"
	${RUN}cd ${WRKSRC}/hadrian/bootstrap && \
		${PKGSRC_SETENV} ${ALL_ENV} FILESDIR=${FILESDIR:Q} \
			python bootstrap.py \
				-j ${_MAKE_JOBS_N} \
				-s ${DISTDIR}/${DIST_SUBDIR}/${HADRIAN_BOOT_SOURCE}

# This defines how to run the Hadrian command. Also used in do-build and
# such.
HADRIAN_CMD=	${PKGSRC_SET_ENV} ${ALL_ENV} ${WRKSRC}/hadrian/bootstrap/_build/bin/hadrian


# -----------------------------------------------------------------------------
# An unusual target "bootstrap"
#
# Build a bootstrapping compiler using an already installed GHC. This is
# certainly impossible if you don't have one. It's absolutely important to
# build it with the fewest possible run-time dependencies, otherwise the
# resulting binary can easily get unusable.

# We don't want our bootkits to have a run-time dependency on libgcc. In
# fact GHC's implementation of Haskell exception handling does not depend
# on libgcc's facilities so it is attractive to do the same for "normal"
# build... but we can't. This is because Haskell programs may call C
# functions via FFI, and those C functions may call C++ functions in turn,
# possibly in a different shared library.
.include "../../mk/compiler.mk"
.if make(bootstrap) && ${CC_VERSION:Mgcc-*}
# But on some platforms gcc automagically inserts a dependency on a shared
# libgcc when -lpthread is given, which is seemingly unavoidable.
LDFLAGS+=	-static-libgcc
.endif

# Gather information about packages on which bootkit depends. It will be
# used in the post-bootstrap phase.
BOOT_GHC_DEPS:=		curses iconv
BOOT_GHC_PKGSRC_DEPS:=	# empty
.for pkg in ${BOOT_GHC_DEPS}

# NOTE: pkglint(1) complains for including these builtin.mk files, telling
# that we must include buildlink3.mk instead. But then how do we get
# variables like USE_BUILTIN.${pkg} defined before including
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

# Compiler wrappers must not remove -I/-L flags for the installed GHC's
# libdir, otherwise the stage-0 GHC (which we are going to use for building
# our bootstraping kit) will not work. Ideally it should be added to
# BUILDLINK_PASSTHRU_DIRS only .if make(bootstrap), but then running
# "${MAKE} wrapper" before "${MAKE} bootstrap" will result in a cryptic
# error which we can't easily catch.
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
BOOT_ARCHIVE.new=		${BOOT_ARCHIVE:S/-${BOOT_VERSION}-/-${PKGVERSION_NOREV}-/}
.if make(bootstrap)
_BARRIER_CMDLINE_TARGETS+=	bootstrap
.endif
.if !defined(_PKGSRC_BARRIER)
bootstrap: barrier
.else
bootstrap: pre-bootstrap .WAIT ${WRKDIR}/stamp-dist-boot .WAIT post-bootstrap
.endif

# For normal build we use pkgsrc libffi.so, but for bootkits we can't do
# that because that would mean bootkits have run-time dependency on
# it. However, building the bundled one isn't a solution either, because
# pkgsrc libffi tends to be heavily patched to support our exotic
# platforms. So we remove ${BUILDLINK_DIR}/lib/libffi.so just before we
# build our bootkit so that the resulting executables link with the static
# one.
CONFIGURE_ARGS.boot=	${CONFIGURE_ARGS.common}
CONFIGURE_ARGS.boot+=	--with-bindist-prefix="ghc-boot-" --with-system-libffi

# Hadrian arguments to use while building a bootkit.
HADRIAN_ARGS.boot=	${HADRIAN_ARGS.common}
HADRIAN_ARGS.boot+=	--docs=none
.if ${OPSYS} == "FreeBSD"
#   -fsplit-sections appears to corrupt the symbol table of stage 1
#   libHSghc-*.a(Instances.o) and cause a linkage failure. Either Clang or
#   LLD is doing something wrong, probably the former.
HADRIAN_ARGS.boot+=	--flavour=bootkit
.else
HADRIAN_ARGS.boot+=	--flavour=bootkit+split_sections
.endif

# Determine the version of GHC being used to build the bootkit. We will
# need this to bootstrap Hadrian.
.if make(bootstrap)
BOOT_GHC_VERSION_CMD=	ghc --numeric-version
BOOT_GHC_VERSION!=	(${BOOT_GHC_VERSION_CMD}) 2>/dev/null || ${ECHO}
HADRIAN_BOOT_SOURCE:=	${HADRIAN_BOOT_SOURCE:S/${BOOT_VERSION}/${BOOT_GHC_VERSION}/}
.endif

.PHONY: pre-bootstrap
pre-bootstrap: wrapper
.if empty(BOOT_GHC_LIBDIR)
	${RUN}if ${BOOT_GHC_LIBDIR_CMD} 2>/dev/null 1>&2; then \
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
	${RUN}if ${TEST} -f ${_COOKIE.configure}; then \
		${ERROR_MSG} "You have already configured the package in a way\
			that building bootstrapping compiler is impossible."; \
		${FAIL_MSG}  "Please run \"${MAKE} clean\" first."; \
	fi

${WRKDIR}/stamp-configure-boot:
	@${PHASE_MSG} "Configuring bootstrapping compiler ${PKGNAME_NOREV}"
	cd ${WRKSRC} && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS.boot}
	${TOUCH} ${.TARGET}

${WRKDIR}/stamp-build-boot: ${WRKDIR}/stamp-configure-boot
	${RUN}${TEST} -f ${DISTDIR}/${DIST_SUBDIR}/${HADRIAN_BOOT_SOURCE} || \
		${FAIL_MSG} "${HADRIAN_BOOT_SOURCE} not found in ${DISTDIR}/${DIST_SUBDIR}.\
			You first need to create it before building the bootkit.\
			See ./files/BOOTSTRAP.md for details."

	@${PHASE_MSG} "Building Hadrian for ${BOOT_GHC_VERSION}"
	${CP} -f ${FILESDIR}/UserSettings.hs ${WRKSRC}/hadrian/
# ${HADRIAN_BOOT_SOURCE} often contains libraries older than what we have
# in pkgsrc. When that happens bootstrap.py tries to build Hadrian with
# pkgsrc-installed libraries and fails because they aren't buildlinked. So
# we must temporarily disable wrappers while building it.
	saved_IFS="$$IFS"; \
	IFS=":"; \
	set -- $$PATH; \
	IFS="$$saved_IFS"; \
	pruned_path=; \
	while ${TEST} "$$#" -gt 0; do \
		if ${TEST} "$$1" != "${WRAPPER_BINDIR}"; then \
			if ${TEST} "$$pruned_path" = ""; then \
				pruned_path="$$1"; \
			else \
				pruned_path="$$pruned_path:$$1"; \
			fi; \
		fi; \
		shift; \
	done; \
	PATH="$$pruned_path"; \
	cd ${WRKSRC}/hadrian/bootstrap && \
		${PKGSRC_SETENV} FILESDIR=${FILESDIR:Q} \
			python bootstrap.py \
				-j ${_MAKE_JOBS_N} \
				-s ${DISTDIR}/${DIST_SUBDIR}/${HADRIAN_BOOT_SOURCE}

	@${PHASE_MSG} "Building bootstrapping compiler ${PKGNAME_NOREV}"
	for f in ${BUILDLINK_DIR:Q}/lib/libffi.*; do \
		case "$$f" in \
			*.a) :;; \
			*)   ${RM} -f "$$f";; \
		esac; \
	done
	cd ${WRKSRC} && ${HADRIAN_CMD} ${HADRIAN_ARGS.boot}
	${TOUCH} ${.TARGET}

${WRKDIR}/stamp-dist-boot: ${WRKDIR}/stamp-build-boot
	@${PHASE_MSG} "Creating binary distribution of bootstrapping ${PKGNAME_NOREV}"
	cd ${WRKSRC} && ${HADRIAN_CMD} ${HADRIAN_ARGS.boot} binary-dist
	${MV} -f ${WRKSRC}/_build/bindist/${BOOT_ARCHIVE.new} ${WRKDIR}/${BOOT_ARCHIVE.new}

.PHONY: post-bootstrap
post-bootstrap:
	@${ECHO} "=========================================================================="
	@${ECHO} "Done creating ${BOOT_ARCHIVE.new}"
	@${ECHO} "  in ${WRKDIR}"
	@${ECHO}
	@${ECHO} "Now you can copy it into ${DISTDIR}/${DIST_SUBDIR} to use as your"
	@${ECHO} "bootstrap kit. You may want to take a backup in case \"lintpkgsrc -r\""
	@${ECHO} "removes it."
	@${ECHO}
	@${ECHO} "Your bootstrap kit has the following run-time dependencies:"
.for pkg in ${BOOT_GHC_DEPS}
	@${PRINTF} "  * %-8s" "${pkg}:"
.  if ${USE_BUILTIN.${pkg}:tl} == no
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
	@${ECHO} "so your bootkit will bitrot more quickly. You may want to rebuild it"
	@${ECHO} "without setting PREFER_PKGSRC to \"yes\"."
.endif
	@${ECHO} "=========================================================================="

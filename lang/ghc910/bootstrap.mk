# $NetBSD: bootstrap.mk,v 1.5 2025/12/28 07:30:17 pho Exp $
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
# * GHC 9.10 requires 9.6 or later to bootstrap.
# * GHC 9.8 requires 9.4 or later to bootstrap.
# * GHC 9.6 requires 9.2 or later to bootstrap.
# * GHC 9.4 requires 9.0 or later to bootstrap.
# * GHC 9.2 requires 8.10 or later to bootstrap.
# * GHC 9.0 requires 8.8 or later to bootstrap.
# * GHC 8.8 requires 8.4 or later to bootstrap.
# * GHC 8.4 requires 8.0 or later to bootstrap.
# * GHC 8.0 requires 7.8 or later to bootstrap.
# * GHC 7.10 requires 7.6 or later to bootstrap.

# GHC has migrated away from GNU Make to Hadrian as its build system. We
# first need to build it in order to build GHC, but a source tarball
# required for building Hadrian is specific to the version of GHC to use
# for bootstrapping. See ./files/BOOTSTRAP.md for instructions on how to
# create one.
HADRIAN_BOOT_SOURCE=	ghc-${BOOT_VERSION}-boot-hadrian-${PKGPATH:T}.tar.gz

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=	9.8.2
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-aarch64-apple-darwin.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=	9.8.2
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-apple-darwin.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
BOOT_VERSION:=	9.8.2
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-freebsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
BOOT_VERSION:=	9.8.2
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-aarch64-unknown-netbsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
BOOT_VERSION:=	9.8.2
BOOT_ARCHIVE:=	ghc-${BOOT_VERSION}-boot-x86_64-unknown-netbsd.tar.xz
DISTFILES:=	${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE} # Available in LOCAL_PORTS
.endif

.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make (makesum) || make(mdi)
BOOT_VERSION:=		9.8.2
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-x86_64-unknown-solaris2.tar.xz
SITES.${BOOT_ARCHIVE}=	https://us-central.manta.mnx.io/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${BOOT_ARCHIVE} ${HADRIAN_BOOT_SOURCE}
.endif

# DISTFILES contains duplicate HADRIAN_BOOT_SOURCE entries at this
# point. Dedupe them now.
DISTFILES:=	${DISTFILES:O:u}

.if empty(BOOT_ARCHIVE)
BOOT_ARCHIVE:=		ghc-${BOOT_VERSION}-boot-unknown.tar.xz
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

# For package developers, please do not upload any bootkits unsafely
# built. That is, machines shared with someone else or on a cloud hosting
# service should be avoided for building bootkits.
.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor


# -----------------------------------------------------------------------------
# The "pre-configure" hook
#
# Install a bootstrapping (stage-0) compiler directly into TOOLS_DIR so
# that ./configure can find it.
#
USE_TOOLS+=	xzcat xz gtar patch
# - patch is for bootstrap.py
# - gtar isn't strictly necessary, but we need a tar(1) implementation
#   supporting --use-compress-program (see
#   patches/patch-hadrian_src_Rules_BinaryDist.hs). Since the option isn't
#   guaranteed to be available everywhere, it's safer to explicitly pull in
#   gtar.

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
		${SED} -e '/^GhcRTSWays/d' < config.mk.in > config.mk.in.tmp && \
		${MV} -f config.mk.in.tmp config.mk.in
# </kludge>
	${RUN}cd ${WRKDIR}/bootkit-dist/${BOOT_ARCHIVE_TOP_DIR} && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} ${SH} ./configure \
			--prefix=${TOOLS_DIR:Q} ${CONFIGURE_ARGS.boot} && \
		${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install
# <kludge>
# A workaround for possible native iconv vs. GNU libiconv mismatch between
# bootkits and the user's choice. See comments in ./files/iconv-bridge.c
	${RUN}${PKGSRC_SETENV} ${ALL_ENV} \
		${CC} -c ${FILESDIR}/iconv-bridge.c -o ${WRKDIR}/iconv-bridge-native.o -DNATIVE; \
		${CC} -c ${FILESDIR}/iconv-bridge.c -o ${WRKDIR}/iconv-bridge-gnu.o; \
		${AR} cr ${WRKDIR}/libiconv-bridge.a \
			${WRKDIR}/iconv-bridge-native.o \
			${WRKDIR}/iconv-bridge-gnu.o; \
		${RANLIB} ${WRKDIR}/libiconv-bridge.a
	${RUN}${AWK} -v WRKDIR=${WRKDIR} -f ${FILESDIR}/inject-iconv-bridge.awk \
		< ${TOOLS_DIR}/bin/ghc > ${TOOLS_DIR}/bin/ghc.tmp
	${RUN}${MV} -f ${TOOLS_DIR}/bin/ghc.tmp ${TOOLS_DIR}/bin/ghc
	${RUN}${CHMOD} +x ${TOOLS_DIR}/bin/ghc
# </kludge>


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
# certainly impossible if you don't have one. A bootkit built with this
# target will have required shared libraries bundled with it, except for
# certain system libraries such as libc, libm, and libpthread.

# MacOS X 10.7 is the oldest macOS version supporting __thread. Although
# ${WRKSRC}/configure has a check for it, the actual build will fail
# without this env. However, setting it to "10.7" will fail if the SDK is
# installed via "xcode-select --install" for an unknown reason. "10.9"
# seems to work. Don't ask why.
.if make(bootstrap) && ${OPSYS} == "Darwin"
MACOSX_DEPLOYMENT_TARGET:=	10.9
.endif

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
# barrier, which we use in CONFIGURE_ARGS. See
# ../../mk/buildlink3/bsd.buildlink3.mk and ../../mk/bsd.pkg.barrier.mk
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

# --with-system-libffi is necessary, otherwise GHC tries to build its own
# copy of libffi, which is bad because the bundled libffi tends not to work
# flawlessly on exotic platforms we intend to support.
CONFIGURE_ARGS.boot=	${CONFIGURE_ARGS.common}
CONFIGURE_ARGS.boot+=	--with-bindist-prefix="ghc-boot-" --with-system-libffi

# Hadrian arguments to use while building a bootkit.
HADRIAN_ARGS.boot=	${HADRIAN_ARGS.common}
HADRIAN_ARGS.boot+=	--prefix=${PREFIX:Q} # Needed because of our patch to Rules.BinaryDist
HADRIAN_ARGS.boot+=	--docs=none
.if ${OPSYS} == "FreeBSD"
#   -fsplit-sections appears to corrupt the symbol table of stage 1
#   libHSghc-*.a(Instances.o) and cause a linkage failure. Either Clang or
#   LLD is doing something wrong, probably the former. TODO: Check and see
#   if the problem has gone. This workaround bloats the binary size.
HADRIAN_ARGS.boot+=	--flavour=bootkit
.else
HADRIAN_ARGS.boot+=	--flavour=bootkit+split_sections
.endif

.if make(bootstrap)
# Determine the version of GHC being used to build the bootkit. We will
# need this to bootstrap Hadrian.
BOOT_GHC_VERSION_CMD=	ghc --numeric-version
BOOT_GHC_VERSION!=	(${BOOT_GHC_VERSION_CMD}) 2>/dev/null || ${ECHO}
HADRIAN_BOOT_SOURCE:=	${HADRIAN_BOOT_SOURCE:S/${BOOT_VERSION}/${BOOT_GHC_VERSION}/}

# Needed because of our patch to Rules.BinaryDist
ALL_ENV+=		BUILDING_BOOTKIT=YES
ALL_ENV+=		SYSTEM_DEFAULT_RPATH=${SYSTEM_DEFAULT_RPATH:Q}

# On ELF platforms we use readelf and patchelf to embed relative rpaths
# into binaries. We cannot use devel/chrpath because it cannot embed rpaths
# longer than existing ones.
.  if ${OBJECT_FMT} == "ELF"
USE_TOOLS+=		readelf
TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf
.  endif
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
# Fail early if we don't have tools we're going to use.
.if ${OBJECT_FMT} == "ELF"
	${RUN}for prog in patchelf readelf; do \
		if ! ${TYPE} $$prog >/dev/null 2>&1; then \
			${ERROR_MSG} "You don't have $$prog in your PATH."; \
			${FAIL_MSG}  "Perhaps you need to run \"${MAKE} clean\" first?"; \
		fi; \
	done
.elif ${OBJECT_FMT} == "Mach-O"
	${RUN}for prog in install_name_tool otool; do \
		if ! ${TYPE} $$prog >/dev/null 2>&1; then \
		${FAIL_MSG} "You don't have $$prog in your PATH, which is\
			necessary to build a bootkit."; \
		fi; \
	done
.else
	${FAIL_MSG} "Sorry but we don't know how to build a bootkit on\
		platforms whose object format is ${OBJECT_FMT}."
.endif

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
	@${ECHO} "=========================================================================="

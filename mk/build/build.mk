# $NetBSD: build.mk,v 1.22 2017/06/01 02:15:10 jlam Exp $
#
# This file defines what happens in the build phase, excluding the
# self-test, which is defined in test.mk.
#
# Public targets for developers:
#
# build-env:
#	Runs an interactive shell (BUILD_ENV_SHELL) in the environment
#	that is used for building the package.
#
# Package-settable variables:
#
# BUILD_MAKE_FLAGS is the list of arguments that is passed to the make
#	process, in addition to the usual MAKE_FLAGS.
#
# BUILD_TARGET is the target from ${MAKE_FILE} that should be invoked
#	to build the sources.
#
# MAKE_JOBS_SAFE
#	Whether the package supports parallel builds. If set to yes,
#	at most MAKE_JOBS jobs are carried out in parallel. The default
#	value is "yes", and packages that don't support it must
#	explicitly set it to "no".
#
#	Keywords: parallel
#
# Variables defined in this file:
#
# BUILD_MAKE_CMD
#	This command sets the proper environment for the build phase
#	and runs make(1) on it. It takes a list of make targets and
#	flags as argument.
#
# See also:
#	mk/build/test.mk
#
# Keywords: build make

_VARGROUPS+=		build
_USER_VARS.build=	MAKE_JOBS BUILD_ENV_SHELL
_PKG_VARS.build=	MAKE_ENV MAKE_FLAGS BUILD_MAKE_FLAGS BUILD_TARGET MAKE_JOBS_SAFE
_SYS_VARS.build=	BUILD_MAKE_CMD

BUILD_MAKE_FLAGS?=	# none
BUILD_TARGET?=		all

BUILD_MAKE_CMD= \
	${PKGSRC_SETENV} ${MAKE_ENV}					\
		${MAKE_PROGRAM} ${_MAKE_JOBS}				\
			${MAKE_FLAGS} ${BUILD_MAKE_FLAGS}		\
			-f ${MAKE_FILE}

.if defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO])
_MAKE_JOBS=	# nothing
.elif defined(MAKE_JOBS)
_MAKE_JOBS=	-j${MAKE_JOBS}
.endif

######################################################################
### build (PUBLIC)
######################################################################
### build is a public target to build the sources from the package.
###
_BUILD_TARGETS+=	check-vulnerable
_BUILD_TARGETS+=	configure
_BUILD_TARGETS+=	acquire-build-lock
_BUILD_TARGETS+=	${_COOKIE.build}
_BUILD_TARGETS+=	release-build-lock
.if ${_USE_NEW_PKGINSTALL:Uno} == "no"
_BUILD_TARGETS+=	pkginstall
.endif

.PHONY: build
.if !target(build)
.  if exists(${_COOKIE.build})
build:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
build: ${_BUILD_TARGETS}
.  else
build: barrier
.  endif
.endif

.PHONY: acquire-build-lock release-build-lock
acquire-build-lock: acquire-lock
release-build-lock: release-lock

.if exists(${_COOKIE.build})
${_COOKIE.build}:
	@${DO_NADA}
.else
${_COOKIE.build}: real-build
.endif

######################################################################
### rebuild (PUBLIC)
######################################################################
### rebuild is a special target to re-run the build target.
###

.PHONY: rebuild
rebuild: build-clean
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} build

######################################################################
### build-clean (PRIVATE)
######################################################################
### build-clean removes the state files for the "build" and
### later phases so that the "build" target may be re-invoked.
###
.PHONY: build-clean
build-clean: install-clean _package-clean
	${RUN} ${RM} -f ${_COOKIE.build}

######################################################################
### real-build (PRIVATE)
######################################################################
### real-build is a helper target onto which one can hook all of the
### targets that do the actual building of the sources.
###
_REAL_BUILD_TARGETS+=	build-check-interactive
_REAL_BUILD_TARGETS+=	build-message
_REAL_BUILD_TARGETS+=	build-vars
_REAL_BUILD_TARGETS+=	pre-build-checks-hook
_REAL_BUILD_TARGETS+=	pre-build
_REAL_BUILD_TARGETS+=	do-build
_REAL_BUILD_TARGETS+=	post-build
_REAL_BUILD_TARGETS+=	build-cookie
_REAL_BUILD_TARGETS+=	error-check

.PHONY: real-build
real-build: ${_REAL_BUILD_TARGETS}

.PHONY: build-message
build-message:
	@${PHASE_MSG} "Building for ${PKGNAME}"

######################################################################
### build-check-interactive (PRIVATE)
######################################################################
### build-check-interactive checks whether we must do an interactive
### build or not.
###
build-check-interactive:
.if !empty(INTERACTIVE_STAGE:Mbuild) && defined(BATCH)
	@${ERROR_MSG} "The build stage of this package requires user interaction"
	@${ERROR_MSG} "Please build manually with:"
	@${ERROR_MSG} "    \"cd ${.CURDIR} && ${MAKE} build\""
	${RUN} ${FALSE}
.else
	@${DO_NADA}
.endif

######################################################################
### pre-build, do-build, post-build (PUBLIC, override)
######################################################################
### {pre,do,post}-build are the heart of the package-customizable
### build targets, and may be overridden within a package Makefile.
###
.PHONY: pre-build do-build post-build

.if !target(do-build)
do-build:
.  for _dir_ in ${BUILD_DIRS}
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${BUILD_MAKE_CMD} ${BUILD_TARGET}
.  endfor
.endif

.if !target(pre-build)
pre-build:
	@${DO_NADA}
.endif

.if !target(post-build)
post-build:
	@${DO_NADA}
.endif

BUILD_ENV_SHELL?=	${SH}
.if defined(_PKGSRC_BARRIER)
build-env: .PHONY configure
	@${STEP_MSG} "Entering the build environment for ${PKGNAME}"
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${BUILD_ENV_SHELL}
.else
build-env: barrier
.endif

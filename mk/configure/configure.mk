# $NetBSD: configure.mk,v 1.23 2008/02/07 21:36:13 rillig Exp $
#
# = Package-settable variables =
#
# CONFIGURE_ENV is the shell environment that is exported to the
#	configure script.
#
# CONFIG_SHELL is the shell that is used for interpreting the
#	configure script.
#
# CONFIGURE_SCRIPT is the path to the script to run in order to
#	configure the software for building.  If the path is relative,
#	then it is assumed to be relative to each directory listed in
#	CONFIGURE_DIRS.
#
# CONFIGURE_ARGS is the list of arguments that is passed to the
#	configure script.
#
# INSTALL_SH_OVERRIDE is a list of files relative to WRKSRC which
#	should be overridden by the install-sh script from
#	sysutils/install-sh.  If not defined or set to "no", then
#	no files are overridden.
#
#	Possible values: no, defined, undefined.
#
#	Default value: defined when GNU_CONFIGURE is defined, undefined
#	otherwise.
#
# OVERRIDE_GNU_CONFIG_SCRIPTS
#	Whether to override the GNU config.guess and config.sub scripts
#	with the pkgsrc versions.
#
#	Possible values: defined, undefined.
#
#	Default value: defined when GNU_CONFIGURE is defined, undefined
#	otherwise.
#
# Command-line variables:
#
# CONFIG_SHELL_FLAGS
#	Set this to -x when you really need to see all commands that the
#	configure script executes.
#
# Keywords: config.guess config.sub
#

_VARGROUPS+=		configure
_USER_VARS.configure=	CONFIG_SHELL_FLAGS
_PKG_VARS.configure=	CONFIGURE_ENV CONFIG_SHELL CONFIGURE_SCRIPT \
	CONFIGURE_ARGS OVERRIDE_GNU_CONFIG_SCRIPTS HAS_CONFIGURE \
	GNU_CONFIGURE PKGCONFIG_OVERRIDE USE_PKGLOCALEDIR \
	CMAKE_ARGS CMAKE_ARG_PATH

CONFIGURE_SCRIPT?=	./configure
CONFIGURE_ENV+=		${ALL_ENV}
CONFIGURE_ARGS?=	# empty
CONFIG_SHELL?=		${SH}
CONFIG_SHELL_FLAGS?=	# none
CMAKE_ARGS?=		# empty
CMAKE_ARG_PATH?=	.
_BUILD_DEFS+=		CONFIGURE_ENV CONFIGURE_ARGS CMAKE_ARGS

.if defined(GNU_CONFIGURE)
.  include "gnu-configure.mk"
.endif
.if defined(OVERRIDE_GNU_CONFIG_SCRIPTS)
.  include "config-override.mk"
.endif
.if defined(INSTALL_SH_OVERRIDE) && empty(INSTALL_SH_OVERRIDE:M[Nn][Oo])
.  include "install-sh-override.mk"
.endif
.if defined(USE_LIBTOOL)
.  include "libtool-override.mk"
.endif
.if defined(PKGCONFIG_OVERRIDE)
.  include "pkg-config-override.mk"
.endif
.include "replace-interpreter.mk"
.if defined(USE_PKGLOCALEDIR)
.  include "replace-localedir.mk"
.endif
.if defined(USE_CMAKE)
.  include "cmake.mk"
.endif

######################################################################
### configure (PUBLIC)
######################################################################
### configure is a public target to configure the sources for building.
###
_CONFIGURE_TARGETS+=	check-vulnerable
_CONFIGURE_TARGETS+=	wrapper
_CONFIGURE_TARGETS+=	acquire-configure-lock
_CONFIGURE_TARGETS+=	${_COOKIE.configure}
_CONFIGURE_TARGETS+=	release-configure-lock

.PHONY: configure
.if !target(configure)
.  if exists(${_COOKIE.configure})
configure:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
configure: ${_CONFIGURE_TARGETS}
.  else
configure: barrier
.  endif
.endif

.PHONY: acquire-configure-lock release-configure-lock
acquire-configure-lock: acquire-lock
release-configure-lock: release-lock

.if exists(${_COOKIE.configure})
${_COOKIE.configure}:
	@${DO_NADA}
.else
${_COOKIE.configure}: real-configure
.endif

######################################################################
### real-configure (PRIVATE)
######################################################################
### real-configure is a helper target onto which one can hook all of the
### targets that do the actual configuration of the sources.
###
#
# Note: pre-configure-checks-hook comes after pre-configure to allow
# packages for fixing bad files with SUBST_STAGE.* = pre-configure.
#
_REAL_CONFIGURE_TARGETS+=	configure-check-interactive
_REAL_CONFIGURE_TARGETS+=	configure-message
_REAL_CONFIGURE_TARGETS+=	configure-vars
_REAL_CONFIGURE_TARGETS+=	pre-configure
_REAL_CONFIGURE_TARGETS+=	do-configure-pre-hook
_REAL_CONFIGURE_TARGETS+=	pre-configure-checks-hook
_REAL_CONFIGURE_TARGETS+=	do-configure
_REAL_CONFIGURE_TARGETS+=	do-configure-post-hook
_REAL_CONFIGURE_TARGETS+=	post-configure
_REAL_CONFIGURE_TARGETS+=	_configure-cookie
_REAL_CONFIGURE_TARGETS+=	error-check

.PHONY: real-configure
real-configure: ${_REAL_CONFIGURE_TARGETS}

.PHONY: configure-message
configure-message:
	@${PHASE_MSG} "Configuring for ${PKGNAME}"

######################################################################
### configure-check-interactive (PRIVATE)
######################################################################
### configure-check-interactive checks whether we must do an interactive
### configuration or not.
###
configure-check-interactive:
.if !empty(INTERACTIVE_STAGE:Mconfigure) && defined(BATCH)
	@${ERROR_MSG} "The configure stage of this package requires user interaction"
	@${ERROR_MSG} "Please configure manually with:"
	@${ERROR_MSG} "    \"cd ${.CURDIR} && ${MAKE} configure\""
	${RUN} ${FALSE}
.else
	@${DO_NADA}
.endif

######################################################################
### do-configure-pre-hook (PRIVATE)
######################################################################
### do-configure-pre-hook is a helper target onto which one can hook
### all of the targets that should be run after pre-configure but before
### do-configure.  These targets typically edit the files used by the
### do-configure target.
###
.PHONY: do-configure-pre-hook
do-configure-pre-hook:
	@${DO_NADA}

######################################################################
### do-configure-post-hook (PRIVATE)
######################################################################
### do-configure-post-hook is a helper target onto which one can hook
### all of the targets that should be run after do-configure but before
### post-configure.  These targets typically edit the files generated
### by the do-configure target that are used during the build phase.
###
.PHONY: do-configure-post-hook
do-configure-post-hook:
	@${DO_NADA}

######################################################################
### do-configure-script (PRIVATE)
######################################################################
### do-configure-script runs the configure script to configure the
### software for building.
###
_CONFIGURE_SCRIPT_ENV+=	INSTALL=${INSTALL:Q}\ -c\ -o\ ${BINOWN}\ -g\ ${BINGRP}
_CONFIGURE_SCRIPT_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
_CONFIGURE_SCRIPT_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
_CONFIGURE_SCRIPT_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}
_CONFIGURE_SCRIPT_ENV+=	INSTALL_GAME=${INSTALL_GAME:Q}
_CONFIGURE_SCRIPT_ENV+=	INSTALL_GAME_DATA=${INSTALL_GAME_DATA:Q}
_CONFIGURE_SCRIPT_ENV+=	${CONFIGURE_ENV}

.PHONY: do-configure-script
do-configure-script:
.for _dir_ in ${CONFIGURE_DIRS}
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${_CONFIGURE_SCRIPT_ENV}				\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
			${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endfor

######################################################################
### do-configure-imake (PRIVATE)
######################################################################
### do-configure-imake runs xmkmf and imake to configure the software
### for building.
###
_CONFIGURE_IMAKE_ENV+=	XPROJECTROOT=${X11BASE:Q}
_CONFIGURE_IMAKE_ENV+=	${SCRIPTS_ENV}

.PHONY: do-configure-imake
do-configure-imake:
.for _dir_ in ${CONFIGURE_DIRS}
	${RUN}								\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${_CONFIGURE_IMAKE_ENV} ${XMKMF}
.endfor

######################################################################
### do-configure-cmake (PRIVATE)
######################################################################
### do-configure-cmake runs cmake to configure the software for
### building.
###
_CONFIGURE_CMAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR}
_CONFIGURE_CMAKE_ENV+=	${CONFIGURE_ENV}


.PHONY: do-configure-cmake
do-configure-cmake:
.for _dir_ in ${CONFIGURE_DIRS}
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${_CONFIGURE_CMAKE_ENV}				\
		cmake ${CMAKE_ARGS} ${CMAKE_ARG_PATH}
.endfor

######################################################################
### pre-configure, do-configure, post-configure (PUBLIC, override)
######################################################################
### {pre,do,post}-configure are the heart of the package-customizable
### configure targets, and may be overridden within a package Makefile.
###
.PHONY: pre-configure do-configure post-configure

_DO_CONFIGURE_TARGETS+=	${HAS_CONFIGURE:D	do-configure-script}
_DO_CONFIGURE_TARGETS+=	${USE_IMAKE:D		do-configure-imake}
_DO_CONFIGURE_TARGETS+=	${USE_CMAKE:D		do-configure-cmake}

.if !target(do-configure)
do-configure: ${_DO_CONFIGURE_TARGETS}
	@${DO_NADA}
.endif

.if !target(pre-configure)
pre-configure:
	@${DO_NADA}
.endif

.if !target(post-configure)
post-configure:
	@${DO_NADA}
.endif

# configure-help:
#	Runs ${CONFIGURE_SCRIPT} --help. It is mainly intended for
#	package developers so they can quickly see the options of the
#	configure script.
#
configure-help:
.for d in ${CONFIGURE_DIRS}
	${RUN} cd ${WRKSRC} && cd ${d} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV} ${CONFIG_SHELL} ${CONFIGURE_SCRIPT} --help
.endfor

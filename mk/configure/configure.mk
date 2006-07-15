# $NetBSD: configure.mk,v 1.6 2006/07/15 23:58:52 rillig Exp $
#
# CONFIGURE_SCRIPT is the path to the script to run in order to
#	configure the software for building.  If the path is relative,
#	then it is assumed to be relative to each directory listed in
#	CONFIGURE_DIRS.
#
# CONFIGURE_ENV is the shell environment that is exported to the
#	configure script.
#
# CONFIGURE_ARGS is the list of arguments that is passed to the
#	configure script.
#
CONFIGURE_SCRIPT?=	./configure
CONFIGURE_ENV+=		${ALL_ENV}
CONFIGURE_ARGS?=	# empty
_BUILD_DEFS+=		CONFIGURE_ENV CONFIGURE_ARGS

.if defined(GNU_CONFIGURE)
.  include "${PKGSRCDIR}/mk/configure/gnu-configure.mk"
.endif
.if defined(OVERRIDE_GNU_CONFIG_SCRIPTS)
.  include "${PKGSRCDIR}/mk/configure/config-override.mk"
.endif
.if defined(USE_LIBTOOL)
.  include "${PKGSRCDIR}/mk/configure/libtool-override.mk"
.endif
.if defined(PKGCONFIG_OVERRIDE)
.  include "${PKGSRCDIR}/mk/configure/pkg-config-override.mk"
.endif
.include "${PKGSRCDIR}/mk/configure/replace-interpreter.mk"
.if defined(USE_PKGLOCALEDIR)
.  include "${PKGSRCDIR}/mk/configure/replace-localedir.mk"
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
.  elif exists(${_COOKIE.barrier})
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
_REAL_CONFIGURE_TARGETS+=	configure-check-interactive
_REAL_CONFIGURE_TARGETS+=	configure-message
_REAL_CONFIGURE_TARGETS+=	configure-vars
_REAL_CONFIGURE_TARGETS+=	pre-configure
_REAL_CONFIGURE_TARGETS+=	do-configure-pre-hook
_REAL_CONFIGURE_TARGETS+=	do-configure
_REAL_CONFIGURE_TARGETS+=	do-configure-post-hook
_REAL_CONFIGURE_TARGETS+=	post-configure
_REAL_CONFIGURE_TARGETS+=	configure-cookie
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
	@${TOUCH} ${_INTERACTIVE_COOKIE}
	@${FALSE}
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
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${_CONFIGURE_SCRIPT_ENV}				\
		${CONFIG_SHELL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
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
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${_CONFIGURE_IMAKE_ENV} ${XMKMF}
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

# $NetBSD: build-defs-message.mk,v 1.2 2006/11/04 21:54:26 rillig Exp $
#

# The build-defs-message target shows the variables that can be configured
# by the pkgsrc user in mk.conf.
#

BUILD_DEFS?=		# none
BUILD_DEFS_EFFECTS?=	# none

.if !empty(PKGSRC_SHOW_BUILD_DEFS:M[yY][eE][sS]) && !exists(${WRKDIR}/.bdm_done)
pre-depends-hook: build-defs-message
.endif

.PHONY: build-defs-message
build-defs-message:
build-defs-message: ${WRKDIR}
.if !empty(BUILD_DEFS:M*)
	@${ECHO} "=========================================================================="
	@${ECHO} "The following variables will affect the build process of this package,"
	@${ECHO} "${PKGNAME}.  Their current value is shown below:"
	@${ECHO} ""
.  for var in ${BUILD_DEFS:O}
.    if !defined(${var})
	@${ECHO} "        * ${var} (not defined)"
.    elif defined(${var}) && empty(${var})
	@${ECHO} "        * ${var} (defined)"
.    else
	@${ECHO} "        * ${var} = ${${var}}"
.    endif
.  endfor
.  if !empty(BUILD_DEFS_EFFECTS:M*)
	@${ECHO} ""
	@${ECHO} "Based on these variables, the following variables have been set:"
	@${ECHO} ""
.  endif
.  for v in ${BUILD_DEFS_EFFECTS}
.    if !defined(${v})
	@${ECHO} "        * ${v} (not defined)"
.    elif defined(${v}) && empty(${v})
	@${ECHO} "        * ${v} (defined, but empty)"
.    else
	@${ECHO} "        * ${v} = "${${v}:Q}""
.    endif
.  endfor
	@${ECHO} ""
	@${ECHO} "You may want to abort the process now with CTRL-C and change their value"
	@${ECHO} "before continuing.  Be sure to run \`${MAKE} clean' after"
	@${ECHO} "the changes."
	@${ECHO} "=========================================================================="
	@${TOUCH} ${WRKDIR}/.bdm_done
.endif

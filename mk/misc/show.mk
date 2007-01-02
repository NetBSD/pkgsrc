# $NetBSD: show.mk,v 1.1 2007/01/02 21:29:07 rillig Exp $
#
# This file contains some targets that print information gathered from
# variables. They do not modify any variables.
#

# show-tools:
#	Emits a /bin/sh shell script that defines all known tools
#	to the values they have in the pkgsrc infrastructure.
#
show-tools: .PHONY
.for t in ${_USE_TOOLS}
.  if defined(_TOOLS_VARNAME.${t})
	@${ECHO} ${_TOOLS_VARNAME.${t}:Q}=${${_TOOLS_VARNAME.${t}}:Q:Q}
.  endif
.endfor

# show-build-defs:
#	Prints the variables that can be configured by the pkgsrc user
#	in mk.conf, and the effects that those settings have.
#

BUILD_DEFS?=		# none
BUILD_DEFS_EFFECTS?=	# none

.if !empty(PKGSRC_SHOW_BUILD_DEFS:M[yY][eE][sS])
pre-depends-hook: show-build-defs
.endif

show-build-defs: .PHONY
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
	@${ECHO} "        * ${var} = "${${var}:Q}
.    endif
.  endfor
.  if !empty(BUILD_DEFS_EFFECTS:M*)
	@${ECHO} ""
	@${ECHO} "Based on these variables, the following variables have been set:"
	@${ECHO} ""
.  endif
.  for var in ${BUILD_DEFS_EFFECTS:O}
.    if !defined(${var})
	@${ECHO} "        * ${var} (not defined)"
.    elif defined(${var}) && empty(${var})
	@${ECHO} "        * ${var} (defined, but empty)"
.    else
	@${ECHO} "        * ${var} = "${${var}:Q}
.    endif
.  endfor
	@${ECHO} ""
	@${ECHO} "You may want to abort the process now with CTRL-C and change their value"
	@${ECHO} "before continuing.  Be sure to run \`${MAKE} clean' after"
	@${ECHO} "the changes."
	@${ECHO} "=========================================================================="
.endif

# @deprecated -- remove after 2007Q1
build-defs-message: show-build-defs .PHONY

# $NetBSD: bsd.makevars.mk,v 1.2 2005/06/01 17:05:19 jlam Exp $
#
# This Makefile fragment is included by bsd.prefs.mk to set all of
# the variables saved through MAKEVARS.  Typical usage is:
#
# .include "../../mk/bsd.prefs.mk"
#
# .if !define(EXPENSIVE_VAR)
# EXPENSIVE_VAR!=	( ... an expensive computation ... )
# .endif
# MAKEVARS+=	EXPENSIVE_VAR
#
# This causes EXPENSIVE_VAR to be computed, then subsequently stored in
# the variable cache file.  The next time through, EXPENSIVE_VAR is
# set by bsd.makevars.mk, which avoids running the expensive computation
# again.
#
# The cache files are created as we pass through each phase of the build,
# and we only include the latest cache file that was created.
#

.if !defined(_REV_ALL_PHASES)
_REV_ALL_PHASES=	# empty
.  for _phase_ in ${ALL_PHASES}
_REV_ALL_PHASES:=	${_phase_} ${_REV_ALL_PHASES}
.  endfor
.endif
MAKEVARS+=	_REV_ALL_PHASES

# Try including the *.makevars.mk files in reverse order so that the
# latest file is included and no more.  We check for _MAKEVARS_MK since
# all of the *.makevars.mk files define this symbol at the top of the
# file.
#
.for _phase_ in ${_REV_ALL_PHASES}
_MAKEVARS_MK.${_phase_}=	${WRKDIR}/.${_phase_}_makevars.mk
.  if !target(${_phase_}-vars)
${_phase_}-vars: ${_MAKEVARS_MK.${_phase_}}
.  endif
.  if !defined(_MAKEVARS_MK)
.    sinclude "${_MAKEVARS_MK.${_phase_}}"
.  endif
.endfor

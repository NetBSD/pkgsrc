# $NetBSD: ghostscript.mk,v 1.6 2002/09/14 03:17:31 rh Exp $
#
# This Makefile fragment is included by packages that require a run-time
# dependency on a ghostscript Postscript interpreter.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally set GHOSTSCRIPT_REQD to the minimum version number of
#     Ghostscript required by the package,
# (2) Optionally set USE_GHOSTSCRIPT to "build" to only add a build-time
#     dependency on Ghostscript,
# (3) And include this Makefile fragment in the package Makefile,

.include "../../mk/bsd.prefs.mk"

GHOSTSCRIPT_REQD?=	6.01
USE_GHOSTSCRIPT?=	run

.if defined(NO_X11)
_GS_PKGSRCDIR?=	../../print/ghostscript-gnu-nox11
.else
_GS_PKGSRCDIR?=	../../print/ghostscript-gnu-x11
.endif

_VALID_GS=	# empty

# ghostscript-gnu{,-x11,-nox11} satisfies ${GHOSTSCRIPT_REQD}<=7.05nb1
#
.for _gs_pattern_ in [0-6].* 7.0 7.0nb* 7.0[0-4] 7.0[0-4]nb* 7.05 7.05nb1
.  if !empty(GHOSTSCRIPT_REQD:M${_gs_pattern_})
.    if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_VALID_GS+=	ghostscript-gnu>=${GHOSTSCRIPT_REQD}
_VALID_GS+=	ghostscript-gnu-x11>=${GHOSTSCRIPT_REQD}
.    else
_VALID_GS+=	ghostscript-gnu>=${GHOSTSCRIPT_REQD}
_VALID_GS+=	ghostscript-gnu-x11>=${GHOSTSCRIPT_REQD}
_VALID_GS+=	ghostscript-gnu-no11>=${GHOSTSCRIPT_REQD}
.    endif
.  endif
.endfor

# ghostscript{,-nox11} satisfies ${GHOSTSCRIPT_REQD}<=6.01nb4.
#
.for _gs_pattern_ in [0-5].* 6.0 6.0nb* 6.01 6.01nb[1-4]
.  if !empty(GHOSTSCRIPT_REQD:M${_gs_pattern_})
.    if defined(USE_X11) || defined(USE_X11BASE) || defined(USE_IMAKE)
_VALID_GS+=	ghostscript>=${GHOSTSCRIPT_REQD}
.    else
_VALID_GS+=	ghostscript>=${GHOSTSCRIPT_REQD}
_VALID_GS+=	ghostscript-no11>=${GHOSTSCRIPT_REQD}
.    endif
.  endif
.endfor

.if !defined(GHOSTSCRIPT_DEPENDS) && !empty(_VALID_GS)
_GS_DEPENDS!=	${ECHO} '${_VALID_GS}' | ${SED} -e "s:^ *::" -e "s: :,:g"
.  if !empty(_GS_DEPENDS:M*,*)
GHOSTSCRIPT_DEPENDS=	{${_GS_DEPENDS}}:${_GS_PKGSRCDIR}
.  else
GHOSTSCRIPT_DEPENDS=	${_GS_DEPENDS}:${_GS_PKGSRCDIR}
.  endif
MAKEFLAGS+=		GHOSTSCRIPT_DEPENDS="${GHOSTSCRIPT_DEPENDS}"
.endif

.if (${USE_GHOSTSCRIPT} == "build")
_GS_DEPMETHOD=		BUILD_DEPENDS
.else
USE_GHOSTSCRIPT:=	run
_GS_DEPMETHOD=		DEPENDS
.endif

${_GS_DEPMETHOD}+=	${GHOSTSCRIPT_DEPENDS}

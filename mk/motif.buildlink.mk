# $NetBSD: motif.buildlink.mk,v 1.11 2001/11/21 13:54:14 agc Exp $
#
# This Makefile fragment is included by packages that use Motif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally set USE_MOTIF12 to use a Motif-1.2-compatible installation.
#     Otherwise, assume we want a Motif-2.0-compatible installation.
# (2) Optionally set MOTIFBASE or MOTIF12BASE to choose the Motif-2.0 or
#     Motif-1.2-compatible installation at the named location,
# (3) Or optionally set MOTIF_TYPE or MOTIF12_TYPE to choose a specific
#     Motif-2.0 or Motif-1.2-compatible package to be used,
# (4) And include this Makefile fragment in the package Makefile.

.if !defined(MOTIF_BUILDLINK_MK)
MOTIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(USE_MOTIF12)
#
# If /usr/dt is a valid Motif-1.2 installation, then use it.  Otherwise,
# if ${X11BASE} is valid, then use it.  Otherwise, use the Motif-1.2
# specified by ${MOTIF12_TYPE_DEFAULT}.
#
.  if exists(/usr/dt/include/Xm/Xm.h) && \
      !exists(/usr/dt/include/Xm/Gadget.h)
_MOTIF_TYPE=		dt
.  elif exists(${X11BASE}/include/Xm/Xm.h) && \
        !exists(${X11BASE}/include/Xm/Gadget.h)
_MOTIF_TYPE=		none
.  else
_MOTIF_TYPE=		${MOTIF12_TYPE_DEFAULT}
.  endif
.else
#
# If /usr/dt is a valid Motif-2.0 installation, then use it.  Otherwise,
# check to see if a pkgsrc Motif-2.0 is installed and valid, then use it.
# Otherwise, if ${X11BASE} is valid, then use it.  Otherwise, use the
# Motif-2.0 specified by ${MOTIF_TYPE_DEFAULT}.
#
.  if exists(/usr/dt/include/Xm/Xm.h) && \
      exists(/usr/dt/include/Xm/Gadget.h)
_MOTIF_TYPE=		dt
.  elif exists(${X11BASE}/lib/X11/config/OpenMotif.tmpl) || \
        exists(${LOCALBASE}/lib/X11/config/OpenMotif.tmpl)
_MOTIF_TYPE=		openmotif
.  elif exists(${X11BASE}/lib/X11/config/LessTif.tmpl) || \
        exists(${LOCALBASE}/lib/X11/config/LessTif.tmpl)
_MOTIF_TYPE=		lesstif
.  elif exists(${X11BASE}/include/Xm.h) && \
        exists(${X11BASE}/include/Xm/Gadget.h)
_MOTIF_TYPE=		none
.  else
_MOTIF_TYPE=		${MOTIF_TYPE_DEFAULT}
.  endif
.endif

# If MOTIF_TYPE is set, then let that override the Motif-discovery just
# performed.  We only recognize the tested strings as proper values for
# MOTIF_TYPE.
#
.if defined(USE_MOTIF12)
.  if defined(MOTIF12_TYPE)
.    if (${MOTIF12_TYPE} == "dt") || \
        (${MOTIF12_TYPE} == "lesstif12")
_MOTIF_TYPE=		${MOTIF12_TYPE}
.    endif
.  endif
.else
.  if defined(MOTIF_TYPE)
.    if (${MOTIF_TYPE} == "dt") || \
        (${MOTIF_TYPE} == "lesstif") || \
        (${MOTIF_TYPE} == "openmotif")
_MOTIF_TYPE=		${MOTIF_TYPE}
.    endif
.  endif
.endif

.if defined(USE_MOTIF12)
#
# If MOTIF12BASE is set, then let that override all other Motif-1.2
# discovery just performed.
#
.  if defined(MOTIF12BASE)
_MOTIF_TYPE=		none
_MOTIFBASE=		${MOTIF12BASE}
.  else
.    if ${_MOTIF_TYPE} == "dt"
_MOTIFBASE=		/usr/dt
.    elif ${_MOTIF_TYPE} == "none"
_MOTIFBASE=		${X11BASE}
.    endif
.  endif
.else
#
# If MOTIFBASE is set, then let that override all other Motif-2.0
# discovery just performed.
#
.  if defined(MOTIFBASE)
_MOTIF_TYPE=		none
_MOTIFBASE=		${MOTIFBASE}
.  else
.    if ${_MOTIF_TYPE} == "dt"
_MOTIFBASE=		/usr/dt
.    elif ${_MOTIF_TYPE} == "none"
_MOTIFBASE=		${X11BASE}
.    endif
.  endif
.endif

.if ${_MOTIF_TYPE} == "openmotif"
.  include "../../x11/openmotif/buildlink.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.openmotif}
.elif ${_MOTIF_TYPE} == "lesstif"
.  include "../../x11/lesstif/buildlink.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.lesstif}
.elif ${_MOTIF_TYPE} == "lesstif12"
.  include "../../x11/lesstif12/buildlink.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.lesstif12}
.else
#
# Link the pre-existing Motif libraries and headers in ${_MOTIFBASE} into
# ${BUILDLINK_DIR}.
#
.  include "../../mk/bsd.buildlink.mk"
BUILDLINK_PREFIX.motif=		${_MOTIFBASE}
BUILDLINK_FILES.motif=		include/Mrm/*
BUILDLINK_FILES.motif+=		include/Xm/*
BUILDLINK_FILES.motif+=		include/uil/*
BUILDLINK_FILES.motif+=		lib/libMrm.*
BUILDLINK_FILES.motif+=		lib/libUil.*
BUILDLINK_FILES.motif+=		lib/libXm.*

BUILDLINK_TARGETS.motif=	motif-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.motif}

pre-configure: ${BUILDLINK_TARGETS.motif}
motif-buildlink: _BUILDLINK_USE
.endif

.if defined(USE_MOTIF12)
.  if !defined(MOTIF12BASE)
MOTIF12_TYPE:=		${_MOTIF_TYPE}
MOTIF12BASE=		${_MOTIFBASE}
.  endif
.else
.  if !defined(MOTIFBASE)
MOTIF_TYPE:=		${_MOTIF_TYPE}
MOTIFBASE=		${_MOTIFBASE}
.  endif
.endif

USE_X11BASE=		# defined
MAKE_ENV+=		MOTIFLIB="${MOTIFLIB}"
LDFLAGS+=		-Wl,-R${_MOTIFBASE}/lib
MOTIFLIB?=		-Wl,-R${_MOTIFBASE}/lib -Wl,-R${X11BASE}/lib -L${BUILDLINK_DIR}/lib -lXm -lXp

.endif	# MOTIF_BUILDLINK_MK

# $NetBSD: motif.buildlink2.mk,v 1.7.2.2 2003/03/25 13:42:17 salo Exp $
#
# USE_MOTIF12
#	use a Motif-1.2-compatible installation, otherwise, assume
#	we want a Motif-2.0-compatible installation
#
# MOTIFBASE, MOTIF12BASE
#	choose the Motif-2.0 or Motif-1.2-compatible installation at the
#	named location
#
# MOTIF_TYPE, MOTIF12_TYPE
#	choose a specific Motif-2.0 or Motif-1.2-compatible package.

.if !defined(MOTIF_BUILDLINK2_MK)
MOTIF_BUILDLINK2_MK=	# defined

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
.  include "../../x11/openmotif/buildlink2.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.openmotif}
.elif ${_MOTIF_TYPE} == "lesstif"
.  include "../../x11/lesstif/buildlink2.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.lesstif}
.elif ${_MOTIF_TYPE} == "lesstif12"
.  include "../../x11/lesstif12/buildlink2.mk"
_MOTIFBASE=		${BUILDLINK_PREFIX.lesstif12}
.else
#
# Link the pre-existing Motif libraries and headers in ${_MOTIFBASE} into
# ${BUILDLINK_DIR}.
#
BUILDLINK_PREFIX.motif=		${_MOTIFBASE}
BUILDLINK_FILES.motif=		include/Mrm/*
BUILDLINK_FILES.motif+=		include/Xm/*
BUILDLINK_FILES.motif+=		include/uil/*
BUILDLINK_FILES.motif+=		lib/libMrm.*
BUILDLINK_FILES.motif+=		lib/libUil.*
BUILDLINK_FILES.motif+=		lib/libXm.*

BUILDLINK_TARGETS+=		motif-buildlink

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

USE_X11?=		# defined
MAKE_ENV+=		MOTIFLIB="${MOTIFLIB}"
MAKE_ENV+=		MOTIFBASE="${_MOTIFBASE}"
LDFLAGS+=		-Wl,${_OPSYS_RPATH_NAME}${_MOTIFBASE}/lib
MOTIFLIB?=		-Wl,${_OPSYS_RPATH_NAME}${_MOTIFBASE}/lib -L${_MOTIFBASE}/lib -lXm -lXp

.endif	# MOTIF_BUILDLINK2_MK

# $NetBSD: motif.buildlink.mk,v 1.4 2001/09/13 19:14:52 jlam Exp $
#
# This Makefile fragment is included by packages that use Motif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally set MOTIF_TYPE choose a specific Motif-compatible package
#     to be used.
# (2) Include this Makefile fragment in the package Makefile,

.if !defined(MOTIF_BUILDLINK_MK)
MOTIF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# Default to using OpenMotif for Motif-compatible libraries as it's a
# "real" Motif with full functionality.  On Solaris, default to DT-Motif
# (in /usr/dt).
#
.if ${OPSYS} == "SunOS"
MOTIF_TYPE_DEFAULT?=	dt
.else
MOTIF_TYPE_DEFAULT?=	openmotif
.endif

# If /usr/dt is a valid Motif installation, then use it.  Otherwise, check
# to see if a pkgsrc Motif is installed and valid, then use it.  Otherwise,
# if ${X11BASE} is valid, then use it.  Otherwise, use the Motif specified
# by ${MOTIF_TYPE_DEFAULT}.
#
.if exists(/usr/dt/include/Xm/Xm.h)
_MOTIF_TYPE=		dt
.elif exists(${X11BASE}/lib/X11/config/OpenMotif.tmpl) || \
      exists(${LOCALBASE}/lib/X11/config/OpenMotif.tmpl)
_MOTIF_TYPE=		openmotif
.elif exists(${X11BASE}/lib/X11/config/LessTif.tmpl) || \
      exists(${LOCALBASE}/lib/X11/config/LessTif.tmpl)
_MOTIF_TYPE=		lesstif
.elif exists(${X11BASE}/include/Xm/Xm.h)
_MOTIF_TYPE=		none
.else
_MOTIF_TYPE=		${MOTIF_TYPE_DEFAULT}
.endif

# If MOTIF_TYPE is set, then let that override the Motif-discovery just
# performed.  We only recognize the tested strings as proper values for
# MOTIF_TYPE.
#
.if defined(MOTIF_TYPE)
.  if (${MOTIF_TYPE} == "openmotif") || \
      (${MOTIF_TYPE} == "lesstif") || \
      (${MOTIF_TYPE} == "dt")
_MOTIF_TYPE=		${MOTIF_TYPE}
.  endif
.endif

# If MOTIFBASE is set, then let that override all other Motif-discovery
# just performed.
#
.if defined(MOTIFBASE)
_MOTIF_TYPE=		none
.else
.  if ${_MOTIF_TYPE} == "dt"
MOTIFBASE=		/usr/dt
.  elif ${_MOTIF_TYPE} == "none"
MOTIFBASE=		${X11BASE}
.  endif
.endif

.if ${_MOTIF_TYPE} == "openmotif"
.  include "../../x11/openmotif/buildlink.mk"
MOTIFBASE=		${BUILDLINK_PREFIX.openmotif}
.elif ${_MOTIF_TYPE} == "lesstif"
.  include "../../x11/lesstif/buildlink.mk"
MOTIFBASE=		${BUILDLINK_PREFIX.lesstif}
.else
#
# Link the pre-existing Motif libraries and headers in ${MOTIFBASE} into
# ${BUILDLINK_DIR}.
#
.  include "../../mk/bsd.buildlink.mk"
BUILDLINK_PREFIX.motif=		${MOTIFBASE}
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

USE_X11=		# defined
MAKE_ENV+=		MOTIFLIB="${MOTIFLIB}"
LDFLAGS+=		-Wl,-R${MOTIFBASE}/lib
MOTIFLIB?=		-Wl,-R${MOTIFBASE}/lib -Wl,-R${X11BASE}/lib -L${BUILDLINK_DIR}/lib -lXm -lXp

.endif	# MOTIF_BUILDLINK_MK

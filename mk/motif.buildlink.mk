# $NetBSD: motif.buildlink.mk,v 1.1 2001/09/08 19:52:30 jlam Exp $
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

# Default to using LessTif for Motif-compatible libraries as it's the most
# well-tested with pkgsrc.  We should thoroughly test using OpenMotif and
# switch the default to OpenMotif as it's a "real" Motif with full
# functionality.  On Solaris, default to DT-Motif (in /usr/dt).
#
.if ${OPSYS} == "SunOS"
MOTIF_TYPE_DEFAULT=	dt
.else
MOTIF_TYPE_DEFAULT=	lesstif
.endif
MOTIF_TYPE?=		${MOTIF_TYPE_DEFAULT}

# We only recognize the tested strings as proper values for MOTIF_TYPE.
.if ${MOTIF_TYPE} != "openmotif" && \
    ${MOTIF_TYPE} != "lesstif" && \
    ${MOTIF_TYPE} != "dt"
MOTIF_TYPE=		${MOTIF_TYPE_DEFAULT}
.endif

# If MOTIFBASE is defined, then assume that it points to a valid Motif
# installation.  Otherwise, if /usr/dt is valid and ${MOTIF_TYPE} is "dt",
# then use it.  Otherwise if ${X11BASE} is valid, then use it and check if
# it's from pkgsrc, adding a dependency if necessary.  Otherwise, use the
# Motif specified by ${MOTIF_TYPE}.
#
.if defined(MOTIFBASE)
_NEED_PKGMOTIF=		NO
.else
.  if exists(/usr/dt/include/Xm/Xm.h) && (${MOTIF_TYPE} == "dt")
_NEED_PKGMOTIF=		NO
MOTIFBASE?=		/usr/dt
MOTIF_TYPE=		dt
.  else
.    if exists(${X11BASE}/include/Xm/Xm.h)
MOTIFBASE?=		${X11BASE}
.      if !exists(${X11BASE}/lib/X11/config/OpenMotif.tmpl) && \
          !exists(${X11BASE}/lib/X11/config/LessTif.tmpl)
_NEED_PKGMOTIF=		NO
.      else
_NEED_PKGMOTIF=		YES
.        if exists(${X11BASE}/lib/X11/config/OpenMotif.tmpl)
MOTIF_TYPE=		openmotif
.        elif exists(${X11BASE}/lib/X11/config/LessTif.tmpl)
MOTIF_TYPE=		lesstif
.        endif
.      endif
.    else
_NEED_PKGMOTIF=		YES
MOTIFBASE?=		${X11PREFIX}
MOTIF_TYPE?=		${MOTIF_TYPE_DEFAULT}
.    endif
.  endif
.endif

.if ${_NEED_PKGMOTIF} == "YES"
.  if ${MOTIF_TYPE} == "openmotif"
.    include "../../x11/openmotif/buildlink.mk"
.  elif ${MOTIF_TYPE} == "lesstif"
.    include "../../x11/lesstif/buildlink.mk"
.  endif
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
MAKE_ENV+=		MOTIFBASE="${MOTIFBASE}"
MAKE_ENV+=		MOTIFLIB="${MOTIFLIB}"
LDFLAGS+=		-Wl,-R${MOTIFBASE}/lib
MOTIFLIB?=		-Wl,-R${MOTIFBASE}/lib -Wl,-R${X11BASE}/lib -L${BUILDLINK_DIR}/lib -lXm -lXp

.endif	# MOTIF_BUILDLINK_MK

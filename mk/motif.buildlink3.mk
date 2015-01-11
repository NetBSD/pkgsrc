# $NetBSD: motif.buildlink3.mk,v 1.17 2015/01/11 02:36:31 joerg Exp $
#
# Package-settable variables:
#
# MOTIFBASE
#	choose the Motif-2.0 installation at the named location.
#
# MOTIF_TYPE
#	choose a specific Motif-2.0 package.
#
# Result variables:
#
# MOTIFBASE
#	The chosen Motif installation.
#
# MOTIF_TYPE
#	The chosen Motif package.

.if !defined(MOTIF_BUILDLINK3_MK)
MOTIF_BUILDLINK3_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			MOTIF_TYPE MOTIFBASE

#
# If /usr/dt is a valid Motif-2.0 installation, then use it.  Otherwise,
# check to see if a pkgsrc Motif-2.0 is installed and valid, then use it.
# Otherwise, if ${X11BASE} is valid, then use it.  Otherwise, use the
# Motif-2.0 specified by ${MOTIF_TYPE_DEFAULT}.
#
.if ${X11_TYPE} == "native" && \
      exists(/usr/dt/include/Xm/Xm.h) && \
      exists(/usr/dt/include/Xm/Gadget.h)
_MOTIF_TYPE=		dt
.elif exists(${X11BASE}/lib/X11/config/LessTif.tmpl) || \
	exists(${LOCALBASE}/lib/X11/config/LessTif.tmpl)
_MOTIF_TYPE=		lesstif
.elif exists(${X11BASE}/include/Xm.h) && \
	exists(${X11BASE}/include/Xm/Gadget.h)
_MOTIF_TYPE=		none
.else
_MOTIF_TYPE=		${MOTIF_TYPE_DEFAULT}
.endif

# If MOTIF_TYPE is set, then let that override the Motif-discovery just
# performed.  We only recognize the tested strings as proper values for
# MOTIF_TYPE.
#
.if defined(MOTIF_TYPE)
.  if (${MOTIF_TYPE} == "dt") || \
	(${MOTIF_TYPE} == "lesstif") || \
	(${MOTIF_TYPE} == "motif")
_MOTIF_TYPE=		${MOTIF_TYPE}
.  endif
.endif

#
# If MOTIFBASE is set, then let that override all other Motif-2.0
# discovery just performed.
#
.if defined(MOTIFBASE)
_MOTIF_TYPE=		none
_MOTIFBASE=		${MOTIFBASE}
.else
.  if ${_MOTIF_TYPE} == "dt"
_MOTIFBASE=		/usr/dt
.  elif ${_MOTIF_TYPE} == "none"
_MOTIFBASE=		${X11BASE}
.  endif
.endif

.if ${_MOTIF_TYPE} == "motif"
.  include "../../x11/motif/buildlink3.mk"
.elif ${_MOTIF_TYPE} == "lesstif"
.  include "../../x11/lesstif/buildlink3.mk"
.else
#
# Link the pre-existing Motif libraries and headers in ${_MOTIFBASE} into
# ${BUILDLINK_DIR}.
#
BUILDLINK_PREFIX.motif=	${_MOTIFBASE}

.include "../../mk/x11.buildlink3.mk"
.endif

.if !defined(MOTIFBASE)
MOTIF_TYPE:=		${_MOTIF_TYPE}
MOTIFBASE=		${_MOTIFBASE}
.endif


MAKE_ENV+=		MOTIFLIB=${MOTIFLIB:Q}
MAKE_ENV+=		MOTIFBASE=${_MOTIFBASE:Q}
CPPFLAGS+=		-I${_MOTIFBASE}/include
LDFLAGS+=		-L${_MOTIFBASE}/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${_MOTIFBASE}/lib
MOTIFLIB?=		${COMPILER_RPATH_FLAG}${_MOTIFBASE}/lib \
			-L${_MOTIFBASE}/lib -lXm -lXp

.endif	# MOTIF_BUILDLINK3_MK

# $NetBSD: xaw.buildlink2.mk,v 1.6 2002/12/02 17:07:28 jschauma Exp $

.if !defined(XAW_BUILDLINK2_MK)
XAW_BUILDLINK2_MK=	# defined

# Pull in setting for XAW_TYPE.
XAW_TYPE?=	standard

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
.  include "../../x11/Xaw-Xpm/buildlink2.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw-Xpm}
.elif ${XAW_TYPE} == "3d"
.  include "../../x11/Xaw3d/buildlink2.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw3d}
.elif ${XAW_TYPE} == "neXtaw"
.  include "../../x11/neXtaw/buildlink2.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.neXtaw}
.else
BUILDLINK_PREFIX.Xaw?=	${X11BASE}
.  if ${OPSYS} == "IRIX"
LIBXAW?=		-L${X11BASE}/lib -Wl,-rpath -Wl,${X11BASE}/lib -lXaw
.  else
LIBXAW?=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib -lXaw
.  endif
.endif

MAKE_ENV+=	LIBXAW="${LIBXAW}"

.endif	# XAW_BUILDLINK2_MK

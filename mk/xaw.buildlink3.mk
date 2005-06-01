# $NetBSD: xaw.buildlink3.mk,v 1.2 2005/06/01 18:03:06 jlam Exp $

.if !defined(XAW_BUILDLINK3_MK)
XAW_BUILDLINK3_MK=	# defined

# Pull in setting for XAW_TYPE.
XAW_TYPE?=	standard

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
.  include "../../x11/Xaw-Xpm/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw-Xpm}
.elif ${XAW_TYPE} == "3d"
.  include "../../x11/Xaw3d/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw3d}
.elif ${XAW_TYPE} == "neXtaw"
.  include "../../x11/neXtaw/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.neXtaw}
.else
.  include "../../mk/x11.buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${X11BASE}
.endif

MAKE_ENV+=	LIBXAW="${LIBXAW}"

.endif	# XAW_BUILDLINK3_MK

# $NetBSD: xaw.buildlink2.mk,v 1.2 2002/08/22 08:21:27 jlam Exp $

.if !defined(XAW_BUILDLINK2_MK)
XAW_BUILDLINK2_MK=	# defined

# Pull in setting for XAW_TYPE.
XAW_TYPE?=	standard

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
.include "../../x11/Xaw-Xpm/buildlink2.mk"
.elif ${XAW_TYPE} == "3d"
.include "../../x11/Xaw3d/buildlink2.mk"
.else
LIBXAW?=	-L${X11BASE}/lib -lXaw
.endif
MAKE_ENV+=	LIBXAW="${LIBXAW}"

.endif	# XAW_BUILDLINK2_MK

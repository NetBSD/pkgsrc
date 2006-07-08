# $NetBSD: buildlink3.mk,v 1.21 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGDIPLUS_BUILDLINK3_MK:=	${LIBGDIPLUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdiplus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgdiplus}
BUILDLINK_PACKAGES+=	libgdiplus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgdiplus

.if !empty(LIBGDIPLUS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgdiplus+=	libgdiplus>=1.1.11
BUILDLINK_ABI_DEPENDS.libgdiplus?=	libgdiplus>=1.1.11nb3
BUILDLINK_PKGSRCDIR.libgdiplus?=	../../graphics/libgdiplus
.endif	# LIBGDIPLUS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.24 2008/10/07 13:23:25 kefren Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGDIPLUS_BUILDLINK3_MK:=	${LIBGDIPLUS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgdiplus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgdiplus}
BUILDLINK_PACKAGES+=	libgdiplus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgdiplus

.if ${LIBGDIPLUS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgdiplus+=	libgdiplus>=2.0
BUILDLINK_ABI_DEPENDS.libgdiplus?=	libgdiplus>=2.0
BUILDLINK_PKGSRCDIR.libgdiplus?=	../../graphics/libgdiplus
.endif	# LIBGDIPLUS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

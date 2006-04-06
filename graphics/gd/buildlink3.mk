# $NetBSD: buildlink3.mk,v 1.12 2006/04/06 06:22:02 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GD_BUILDLINK3_MK:=	${GD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngd}
BUILDLINK_PACKAGES+=	gd

.if !empty(GD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gd+=		gd>=2.0.15nb1
BUILDLINK_ABI_DEPENDS.gd+=	gd>=2.0.33nb2
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd
.endif	# GD_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

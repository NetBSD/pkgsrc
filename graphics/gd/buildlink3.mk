# $NetBSD: buildlink3.mk,v 1.11 2006/02/05 23:09:30 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GD_BUILDLINK3_MK:=	${GD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngd}
BUILDLINK_PACKAGES+=	gd

.if !empty(GD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gd+=		gd>=2.0.15nb1
BUILDLINK_RECOMMENDED.gd+=	gd>=2.0.33nb2
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd
.endif	# GD_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

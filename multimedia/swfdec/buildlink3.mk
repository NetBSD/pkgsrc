# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:02 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWFDEC_BUILDLINK3_MK:=	${SWFDEC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swfdec
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswfdec}
BUILDLINK_PACKAGES+=	swfdec
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}swfdec

.if !empty(SWFDEC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.swfdec+=	swfdec>=0.2.2
BUILDLINK_ABI_DEPENDS.swfdec+=	swfdec>=0.2.2nb7
BUILDLINK_PKGSRCDIR.swfdec?=	../../multimedia/swfdec
.endif	# SWFDEC_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.5 2004/10/03 00:14:58 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWFDEC_BUILDLINK3_MK:=	${SWFDEC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swfdec
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswfdec}
BUILDLINK_PACKAGES+=	swfdec

.if !empty(SWFDEC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swfdec+=	swfdec>=0.2.2
BUILDLINK_RECOMMENDED.swfdec+=	swfdec>=0.2.2nb1
BUILDLINK_PKGSRCDIR.swfdec?=	../../graphics/swfdec
.endif	# SWFDEC_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

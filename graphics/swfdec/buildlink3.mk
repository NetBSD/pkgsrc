# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:35 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWFDEC_BUILDLINK3_MK:=	${SWFDEC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swfdec
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswfdec}
BUILDLINK_PACKAGES+=	swfdec

.if !empty(SWFDEC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.swfdec+=	swfdec>=0.2.1nb7
BUILDLINK_PKGSRCDIR.swfdec?=	../../graphics/swfdec

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# SWFDEC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

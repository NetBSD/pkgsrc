# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:55:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use swfdec.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWFDEC_BUILDLINK3_MK:=	${SWFDEC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	swfdec
.endif

.if !empty(SWFDEC_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			swfdec
BUILDLINK_DEPENDS.swfdec+=		swfdec>=0.2.1nb7
BUILDLINK_PKGSRCDIR.swfdec?=		../../graphics/swfdec

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # SWFDEC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.3 2004/03/08 19:52:51 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSTROKE_BUILDLINK3_MK:=	${LIBSTROKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libstroke
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibstroke}
BUILDLINK_PACKAGES+=	libstroke

.if !empty(LIBSTROKE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libstroke+=	libstroke>=0.3nb1
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke

.include "../../lang/tcl83/buildlink3.mk"

.endif	# LIBSTROKE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

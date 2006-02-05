# $NetBSD: buildlink3.mk,v 1.7 2006/02/05 23:08:45 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSTROKE_BUILDLINK3_MK:=	${LIBSTROKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libstroke
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibstroke}
BUILDLINK_PACKAGES+=	libstroke

.if !empty(LIBSTROKE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libstroke+=	libstroke>=0.5.1
BUILDLINK_RECOMMENDED.libstroke+=	libstroke>=0.5.1nb2
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke
.endif	# LIBSTROKE_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

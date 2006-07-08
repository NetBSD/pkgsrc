# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 22:39:12 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSTROKE_BUILDLINK3_MK:=	${LIBSTROKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libstroke
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibstroke}
BUILDLINK_PACKAGES+=	libstroke
BUILDLINK_ORDER+=	libstroke

.if !empty(LIBSTROKE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libstroke+=	libstroke>=0.5.1
BUILDLINK_ABI_DEPENDS.libstroke+=	libstroke>=0.5.1nb2
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke
.endif	# LIBSTROKE_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

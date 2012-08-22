# $NetBSD: buildlink3.mk,v 1.14 2012/08/22 20:39:48 drochner Exp $

BUILDLINK_TREE+=	libstroke

.if !defined(LIBSTROKE_BUILDLINK3_MK)
LIBSTROKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstroke+=	libstroke>=0.5.1
BUILDLINK_ABI_DEPENDS.libstroke+=	libstroke>=0.5.1nb4
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke

.endif # LIBSTROKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstroke

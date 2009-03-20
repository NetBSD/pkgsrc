# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libstroke

.if !defined(LIBSTROKE_BUILDLINK3_MK)
LIBSTROKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstroke+=	libstroke>=0.5.1
BUILDLINK_ABI_DEPENDS.libstroke+=	libstroke>=0.5.1nb2
BUILDLINK_PKGSRCDIR.libstroke?=	../../devel/libstroke

.include "../../lang/tcl/buildlink3.mk"
.endif # LIBSTROKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstroke

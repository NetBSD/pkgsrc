# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libmodplug

.if !defined(LIBMODPLUG_BUILDLINK3_MK)
LIBMODPLUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmodplug+=		libmodplug>=0.7
BUILDLINK_ABI_DEPENDS.libmodplug+=	libmodplug>=0.7nb1
BUILDLINK_PKGSRCDIR.libmodplug?=	../../audio/libmodplug
.endif # LIBMODPLUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmodplug

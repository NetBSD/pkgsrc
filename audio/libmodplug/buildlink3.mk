# $NetBSD: buildlink3.mk,v 1.10 2011/05/05 08:52:43 obache Exp $

BUILDLINK_TREE+=	libmodplug

.if !defined(LIBMODPLUG_BUILDLINK3_MK)
LIBMODPLUG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmodplug+=		libmodplug>=0.7
BUILDLINK_ABI_DEPENDS.libmodplug+=	libmodplug>=0.8.8.1
BUILDLINK_PKGSRCDIR.libmodplug?=	../../audio/libmodplug
.endif # LIBMODPLUG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmodplug

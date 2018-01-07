# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libsidplay

.if !defined(LIBSIDPLAY_BUILDLINK3_MK)
LIBSIDPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsidplay+=	libsidplay>=1.36.38
BUILDLINK_ABI_DEPENDS.libsidplay+=	libsidplay>=1.36.59nb2
BUILDLINK_PKGSRCDIR.libsidplay?=	../../audio/libsidplay
.endif # LIBSIDPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsidplay

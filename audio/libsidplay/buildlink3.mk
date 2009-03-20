# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:56 joerg Exp $

BUILDLINK_TREE+=	libsidplay

.if !defined(LIBSIDPLAY_BUILDLINK3_MK)
LIBSIDPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsidplay+=		libsidplay>=1.36.38
BUILDLINK_ABI_DEPENDS.libsidplay+=	libsidplay>=1.36.59nb2
BUILDLINK_PKGSRCDIR.libsidplay?=	../../audio/libsidplay
.endif # LIBSIDPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsidplay

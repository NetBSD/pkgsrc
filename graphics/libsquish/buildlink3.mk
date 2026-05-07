# $NetBSD: buildlink3.mk,v 1.1 2026/05/07 17:13:47 adam Exp $

BUILDLINK_TREE+=	libsquish

.if !defined(LIBSQUISH_BUILDLINK3_MK)
LIBSQUISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsquish+=	libsquish>=1.15.1.3
BUILDLINK_PKGSRCDIR.libsquish?=		../../graphics/libsquish
.endif	# LIBSQUISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsquish

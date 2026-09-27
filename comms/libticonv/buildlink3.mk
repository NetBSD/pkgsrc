# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:35:17 tnn Exp $

BUILDLINK_TREE+=	libticonv

.if !defined(LIBTICONV_BUILDLINK3_MK)
LIBTICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticonv+=	libticonv>=1.1.3
BUILDLINK_ABI_DEPENDS.libticonv?=		libticonv>=1.1.3nb5
BUILDLINK_PKGSRCDIR.libticonv?=		../../comms/libticonv

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBTICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticonv

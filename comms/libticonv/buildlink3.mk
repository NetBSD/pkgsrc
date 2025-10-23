# $NetBSD: buildlink3.mk,v 1.4 2025/10/23 20:36:07 wiz Exp $

BUILDLINK_TREE+=	libticonv

.if !defined(LIBTICONV_BUILDLINK3_MK)
LIBTICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticonv+=	libticonv>=1.1.3
BUILDLINK_ABI_DEPENDS.libticonv?=		libticonv>=1.1.3nb3
BUILDLINK_PKGSRCDIR.libticonv?=		../../comms/libticonv

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBTICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticonv

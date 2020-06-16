# $NetBSD: buildlink3.mk,v 1.1 2020/06/16 13:46:37 ryoon Exp $

BUILDLINK_TREE+=	libdsk

.if !defined(LIBDSK_BUILDLINK3_MK)
LIBDSK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdsk+=	libdsk>=1.3.8
BUILDLINK_PKGSRCDIR.libdsk?=	../../emulators/libdsk
.endif	# LIBDSK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdsk

# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:11 wiz Exp $

BUILDLINK_TREE+=	libhid

.if !defined(LIBHID_BUILDLINK3_MK)
LIBHID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhid+=	libhid>=0.2
BUILDLINK_ABI_DEPENDS.libhid?=	libhid>=0.2.16nb13
BUILDLINK_PKGSRCDIR.libhid?=	../../devel/libhid
.endif	# LIBHID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhid

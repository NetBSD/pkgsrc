# $NetBSD: buildlink3.mk,v 1.1 2016/07/08 14:29:53 kamil Exp $

BUILDLINK_TREE+=	libcap-ng

.if !defined(LIBCAP_NG_BUILDLINK3_MK)
LIBCAP_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcap-ng+=	libcap-ng>=0.7.9
BUILDLINK_ABI_DEPENDS.libcap-ng+=	libcap-ng>=0.7.9
BUILDLINK_PKGSRCDIR.libcap-ng?=	../../sysutils/libcap-ng
.endif	# LIBCAP_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcap-ng

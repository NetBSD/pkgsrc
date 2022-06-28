# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:57 wiz Exp $

BUILDLINK_TREE+=	libcap

.if !defined(LIBCAP_BUILDLINK3_MK)
LIBCAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcap+=	libcap>=2.25
BUILDLINK_ABI_DEPENDS.libcap?=	libcap>=2.44nb2
BUILDLINK_PKGSRCDIR.libcap?=	../../sysutils/libcap
.endif	# LIBCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcap

# $NetBSD: buildlink3.mk,v 1.1 2016/07/08 14:29:53 kamil Exp $

BUILDLINK_TREE+=	libcap

.if !defined(LIBCAP_BUILDLINK3_MK)
LIBCAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcap+=	libcap>=2.25
BUILDLINK_PKGSRCDIR.libcap?=	../../sysutils/libcap
.endif	# LIBCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcap

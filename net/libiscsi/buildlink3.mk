# $NetBSD: buildlink3.mk,v 1.1 2020/03/13 13:21:39 tnn Exp $

BUILDLINK_TREE+=	libiscsi

.if !defined(LIBISCSI_BUILDLINK3_MK)
LIBISCSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiscsi+=	libiscsi>=1.19.0
BUILDLINK_PKGSRCDIR.libiscsi?=		../../net/libiscsi
.endif	# LIBISCSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiscsi

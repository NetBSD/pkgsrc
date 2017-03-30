# $NetBSD: buildlink3.mk,v 1.1 2017/03/30 01:55:58 schmonz Exp $

BUILDLINK_TREE+=	libsrs2

.if !defined(LIBSRS2_BUILDLINK3_MK)
LIBSRS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsrs2+=	libsrs2>=1.0.18
BUILDLINK_PKGSRCDIR.libsrs2?=	../../mail/libsrs2
.endif	# LIBSRS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsrs2

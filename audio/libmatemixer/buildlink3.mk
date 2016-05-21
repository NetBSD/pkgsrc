# $NetBSD: buildlink3.mk,v 1.1 2016/05/21 18:48:22 youri Exp $

BUILDLINK_TREE+=	libmatemixer

.if !defined(LIBMATEMIXER_BUILDLINK3_MK)
LIBMATEMIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatemixer+=	libmatemixer>=1.12.1
BUILDLINK_PKGSRCDIR.libmatemixer?=	../../audio/libmatemixer

.endif	# LIBMATEMIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatemixer

# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/03/05 05:14:42 agc Exp $

BUILDLINK_TREE+=	libmultigest

.if !defined(LIBMULTIGEST_BUILDLINK3_MK)
LIBMULTIGEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmultigest+=	libmultigest>=20140304
BUILDLINK_PKGSRCDIR.libmultigest?=	../../security/libmultigest
.endif	# LIBMULTIGEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmultigest

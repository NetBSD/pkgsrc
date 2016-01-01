# $NetBSD: buildlink3.mk,v 1.1 2016/01/01 15:25:43 fhajny Exp $

BUILDLINK_TREE+=	libfastjson

.if !defined(LIBFASTJSON_BUILDLINK3_MK)
LIBFASTJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfastjson+=	libfastjson>=0.99
BUILDLINK_ABI_DEPENDS.libfastjson+=	libfastjson>=0.99
BUILDLINK_PKGSRCDIR.libfastjson?=	../../textproc/libfastjson
.endif	# LIBFASTJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfastjson

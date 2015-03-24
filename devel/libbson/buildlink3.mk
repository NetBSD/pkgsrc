# $NetBSD: buildlink3.mk,v 1.5 2015/03/24 13:21:43 fhajny Exp $

BUILDLINK_TREE+=	libbson

.if !defined(LIBBSON_BUILDLINK3_MK)
LIBBSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbson+=	libbson>=1.1.0
BUILDLINK_PKGSRCDIR.libbson?=	../../devel/libbson
.endif	# LIBBSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbson

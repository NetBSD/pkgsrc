# $NetBSD: buildlink3.mk,v 1.6 2015/10/19 11:42:18 fhajny Exp $

BUILDLINK_TREE+=	libbson

.if !defined(LIBBSON_BUILDLINK3_MK)
LIBBSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbson+=	libbson>=1.2.0
BUILDLINK_PKGSRCDIR.libbson?=	../../devel/libbson
.endif	# LIBBSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbson

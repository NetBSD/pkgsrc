# $NetBSD: buildlink3.mk,v 1.1 2014/05/07 15:43:59 fhajny Exp $

BUILDLINK_TREE+=	libbson

.if !defined(LIBBSON_BUILDLINK3_MK)
LIBBSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbson+=	libbson>=0.6.8
BUILDLINK_PKGSRCDIR.libbson?=	../../devel/libbson
.endif	# LIBBSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbson

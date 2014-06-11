# $NetBSD: buildlink3.mk,v 1.2 2014/06/11 13:50:19 fhajny Exp $

BUILDLINK_TREE+=	libbson

.if !defined(LIBBSON_BUILDLINK3_MK)
LIBBSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbson+=	libbson>=0.8.0
BUILDLINK_PKGSRCDIR.libbson?=	../../devel/libbson
.endif	# LIBBSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbson

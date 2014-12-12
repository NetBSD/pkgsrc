# $NetBSD: buildlink3.mk,v 1.4 2014/12/12 11:29:32 fhajny Exp $

BUILDLINK_TREE+=	libbson

.if !defined(LIBBSON_BUILDLINK3_MK)
LIBBSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbson+=	libbson>=1.0.0
BUILDLINK_PKGSRCDIR.libbson?=	../../devel/libbson
.endif	# LIBBSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbson

# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/20 10:12:24 markd Exp $

BUILDLINK_TREE+=	qjson

.if !defined(QJSON_BUILDLINK3_MK)
QJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qjson+=	qjson>=0.7.1
BUILDLINK_PKGSRCDIR.qjson?=	../../devel/qjson

.endif	# QJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-qjson

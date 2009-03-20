# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:12 joerg Exp $

BUILDLINK_TREE+=	whoson

.if !defined(WHOSON_BUILDLINK3_MK)
WHOSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.whoson+=	whoson>=2.03
BUILDLINK_PKGSRCDIR.whoson?=	../../net/whoson
.endif # WHOSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-whoson

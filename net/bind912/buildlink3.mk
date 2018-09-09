# $NetBSD: buildlink3.mk,v 1.1 2018/09/09 13:16:01 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.11.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind911
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

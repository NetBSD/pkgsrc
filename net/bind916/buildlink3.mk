# $NetBSD: buildlink3.mk,v 1.1 2020/08/09 15:20:21 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.16.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind916
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

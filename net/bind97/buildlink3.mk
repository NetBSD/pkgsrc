# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/26 16:11:47 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.7.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind97
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

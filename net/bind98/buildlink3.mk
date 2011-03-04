# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/04 03:52:15 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.8.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind98
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

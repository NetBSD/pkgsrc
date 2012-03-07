# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/07 14:25:00 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.9.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind99
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

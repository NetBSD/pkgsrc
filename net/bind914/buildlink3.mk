# $NetBSD: buildlink3.mk,v 1.1 2019/04/30 03:34:34 taca Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.14.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind914
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

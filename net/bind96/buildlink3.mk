# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:07 joerg Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.6.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind96
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/07/02 02:42:58 jnemeth Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.10.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind910
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

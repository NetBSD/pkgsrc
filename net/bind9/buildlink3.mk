# $NetBSD: buildlink3.mk,v 1.14 2010/01/17 12:02:30 wiz Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.2.2
BUILDLINK_ABI_DEPENDS.bind+=	bind>=9.4.3pl3nb2
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind9

BUILDLINK_INCDIRS.bind?=	include/bind
BUILDLINK_LDFLAGS.bind?=	${BUILDLINK_LDADD.bind}

.include "../../security/openssl/buildlink3.mk"
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind

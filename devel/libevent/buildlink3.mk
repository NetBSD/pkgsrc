# $NetBSD: buildlink3.mk,v 1.23 2016/03/05 11:27:45 jperkin Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=libevent>=2.0.10
BUILDLINK_ABI_DEPENDS.libevent?=	libevent>=2.0.22nb1
BUILDLINK_PKGSRCDIR.libevent?=	../../devel/libevent

.include "../../security/openssl/buildlink3.mk"
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent

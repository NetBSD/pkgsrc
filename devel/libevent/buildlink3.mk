# $NetBSD: buildlink3.mk,v 1.26 2023/10/24 22:08:51 wiz Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=	libevent>=2.1.12nb1
BUILDLINK_PKGSRCDIR.libevent?=		../../devel/libevent

.include "../../security/openssl/buildlink3.mk"
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent

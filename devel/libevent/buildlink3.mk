# $NetBSD: buildlink3.mk,v 1.27 2025/10/05 02:53:06 js Exp $

BUILDLINK_TREE+=	libevent

.if !defined(LIBEVENT_BUILDLINK3_MK)
LIBEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.6
BUILDLINK_ABI_DEPENDS.libevent+=	libevent>=2.1.12nb1
BUILDLINK_PKGSRCDIR.libevent?=		../../devel/libevent

.if ${OPSYS} != "QNX"
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # LIBEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevent

# $NetBSD: buildlink3.mk,v 1.3 2020/01/18 21:48:21 jperkin Exp $

BUILDLINK_TREE+=	unbound

.if !defined(UNBOUND_BUILDLINK3_MK)
UNBOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unbound+=	unbound>=1.6.0
BUILDLINK_ABI_DEPENDS.unbound?=	unbound>=1.9.6nb1
BUILDLINK_PKGSRCDIR.unbound?=	../../net/unbound

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# UNBOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-unbound

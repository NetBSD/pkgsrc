# $NetBSD: buildlink3.mk,v 1.2 2017/07/09 08:09:41 adam Exp $

BUILDLINK_TREE+=	unbound

.if !defined(UNBOUND_BUILDLINK3_MK)
UNBOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unbound+=	unbound>=1.6.0
BUILDLINK_PKGSRCDIR.unbound?=	../../net/unbound

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# UNBOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-unbound

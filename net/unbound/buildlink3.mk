# $NetBSD: buildlink3.mk,v 1.4 2020/11/11 08:04:28 nikita Exp $

BUILDLINK_TREE+=	unbound

.if !defined(UNBOUND_BUILDLINK3_MK)
UNBOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unbound+=	unbound>=1.6.0
BUILDLINK_ABI_DEPENDS.unbound?=	unbound>=1.9.6nb1
BUILDLINK_PKGSRCDIR.unbound?=	../../net/unbound

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
pkgbase := unbound
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.unbound:Mdoh}
.include "../../www/nghttp2/buildlink3.mk"
.endif
.endif	# UNBOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-unbound

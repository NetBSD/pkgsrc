# $NetBSD: buildlink3.mk,v 1.22 2026/05/14 16:42:09 ryoon Exp $

BUILDLINK_TREE+=	riemann-client

.if !defined(RIEMANN_CLIENT_BUILDLINK3_MK)
RIEMANN_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.riemann-client+=	riemann-client>=2
BUILDLINK_ABI_DEPENDS.riemann-client?=	riemann-client>=2.2.0nb14
BUILDLINK_PKGSRCDIR.riemann-client?=	../../sysutils/riemann-client

pkgbase := riemann-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.riemann-client:Mtls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.endif # RIEMANN_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-riemann-client

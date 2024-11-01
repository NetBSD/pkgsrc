# $NetBSD: buildlink3.mk,v 1.16 2024/11/01 00:53:43 wiz Exp $

BUILDLINK_TREE+=	riemann-client

.if !defined(RIEMANN_CLIENT_BUILDLINK3_MK)
RIEMANN_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.riemann-client+=	riemann-client>=2
BUILDLINK_ABI_DEPENDS.riemann-client?=	riemann-client>=2.2.0nb3
BUILDLINK_PKGSRCDIR.riemann-client?=	../../sysutils/riemann-client

pkgbase := riemann-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.riemann-client:Mtls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.endif # RIEMANN_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-riemann-client

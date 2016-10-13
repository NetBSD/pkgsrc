# $NetBSD: buildlink3.mk,v 1.1 2016/10/13 11:03:13 fhajny Exp $

BUILDLINK_TREE+=	riemann-client

.if !defined(RIEMANN_CLIENT_BUILDLINK3_MK)
RIEMANN_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.riemann-client+=	riemann-client>=1.9.0
BUILDLINK_PKGSRCDIR.riemann-client?=	../../sysutils/riemann-client

pkgbase := riemann-client
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.riemann-client:Mtls)
.  include "../../security/gnutls/buildlink3.mk"
.endif

.endif # RIEMANN_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-riemann-client

# $NetBSD: Makefile,v 1.3 2026/09/02 19:04:17 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=		OAuth 2.x and OpenID Connect C library

PKGCONFIG_OVERRIDE+=	liboauth2.pc.in

CONFIGURE_ARGS+=	--without-apache

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/cjose/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

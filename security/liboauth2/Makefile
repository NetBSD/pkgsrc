# $NetBSD: Makefile,v 1.1 2026/06/13 11:06:10 markd Exp $

.include "Makefile.common"

COMMENT=		OAuth 2.x and OpenID Connect C library

PKGCONFIG_OVERRIDE+=	liboauth2.pc.in

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/cjose/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

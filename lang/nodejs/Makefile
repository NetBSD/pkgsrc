# $NetBSD: Makefile,v 1.127 2018/05/03 21:19:16 fhajny Exp $

DISTNAME=	node-v10.0.0

USE_LANGUAGES=	c gnu++14

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

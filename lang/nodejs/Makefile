# $NetBSD: Makefile,v 1.143 2018/09/07 11:45:04 fhajny Exp $

DISTNAME=	node-v10.10.0

USE_LANGUAGES=	c gnu++14

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

# Stated by the changelog
BUILDLINK_API_DEPENDS.libuv+=   libuv>=1.23

.include "../../mk/bsd.prefs.mk"

# Optional OpenSSL support in nghttp2 conflicts with OpenSSL 1.1.x
# bundled and built by lang/nodejs.
# Uncomment when we switch to openssl>=1.1
# CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	deps/openssl/openssl/.travis-create-release.sh

.include "options.mk"

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
# Uncomment when we switch to openssl>=1.1
# .include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.121 2018/03/13 16:22:00 fhajny Exp $

DISTNAME=	node-v9.8.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--shared-nghttp2
CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

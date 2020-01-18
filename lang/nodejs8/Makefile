# $NetBSD: Makefile,v 1.24 2020/01/18 21:48:14 jperkin Exp $

DISTNAME=	node-v8.17.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

PKGREVISION= 1
.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

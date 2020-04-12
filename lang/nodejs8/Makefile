# $NetBSD: Makefile,v 1.29 2020/04/12 08:27:58 adam Exp $

DISTNAME=	node-v8.17.0
PKGREVISION=	2

USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

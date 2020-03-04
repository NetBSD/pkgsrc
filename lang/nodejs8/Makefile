# $NetBSD: Makefile,v 1.27 2020/03/04 18:59:40 adam Exp $

DISTNAME=	node-v8.17.0
PKGREVISION=	1

USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.33 2020/12/16 07:29:36 adam Exp $

DISTNAME=	node-v8.17.0
PKGREVISION=	4

USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

PYTHON_VERSIONS_ACCEPTED=	27

CHECK_PORTABILITY_SKIP+=	tools/macos-installer/*

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

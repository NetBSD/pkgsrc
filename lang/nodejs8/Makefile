# $NetBSD: Makefile,v 1.32 2020/11/05 09:06:57 ryoon Exp $

DISTNAME=	node-v8.17.0
PKGREVISION=	4

USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	tools/macos-installer/*

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

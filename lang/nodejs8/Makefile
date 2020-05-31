# $NetBSD: Makefile,v 1.30 2020/05/31 21:41:22 rillig Exp $

DISTNAME=	node-v8.17.0
PKGREVISION=	2

USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

CHECK_PORTABILITY_SKIP+=	tools/macos-installer/*

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

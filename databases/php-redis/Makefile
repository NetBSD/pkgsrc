# $NetBSD: Makefile,v 1.22 2026/08/12 06:57:47 taca Exp $
#

MODNAME=	redis
PECL_VERSION=	6.3.0
PECL_LEGACY_VERSION_SCHEME=	yes
PECL_DISTNAME=	${PECL_VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=nicolasff/}
GITHUB_PROJECT=	phpredis
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicolasff/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

PHP_REQUIRE_MODULE=	json

PHP_VERSIONS_INCOMPATIBLE=	56

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PECL_VERSION}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../lang/php/compat.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.13 2021/03/07 13:02:29 taca Exp $
#

MODNAME=	redis
PECL_VERSION=	5.3.3
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

PHP_VERSIONS_INCOMPATIBLE=	56

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PECL_VERSION}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

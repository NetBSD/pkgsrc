# $NetBSD: Makefile,v 1.1 2021/03/07 12:58:28 taca Exp $
#

MODNAME=	redis
PKGMODNAME=	redis
PECL_VERSION=	4.3.0
PECL_LEGACY_VERSION_SCHEME=	yes
PECL_DISTNAME=	${PECL_VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=phpredis/}
GITHUB_PROJECT=	phpredis
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phpredis/phpredis
COMMENT=	PHP extension for Redis
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	56

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PECL_VERSION}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

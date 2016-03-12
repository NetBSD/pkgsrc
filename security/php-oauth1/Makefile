# $NetBSD: Makefile,v 1.1 2016/03/12 09:39:57 fhajny Exp $

MODNAME=		oauth
PKGREVISION=		2
PECL_VERSION=		1.2.3
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	55 56

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

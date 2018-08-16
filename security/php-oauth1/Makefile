# $NetBSD: Makefile,v 1.9 2018/08/16 18:55:10 adam Exp $

MODNAME=		oauth
PKGREVISION=		9
PECL_VERSION=		1.2.3
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	56

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

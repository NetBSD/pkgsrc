# $NetBSD: Makefile,v 1.19 2021/04/21 13:25:21 adam Exp $

MODNAME=		oauth
PKGREVISION=		19
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

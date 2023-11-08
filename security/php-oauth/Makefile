# $NetBSD: Makefile,v 1.34 2023/11/08 13:20:49 wiz Exp $

MODNAME=		oauth
PECL_VERSION=		2.0.7
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP oauth consumer extension
PKGREVISION=		7
LICENSE=		modified-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

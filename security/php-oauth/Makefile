# $NetBSD: Makefile,v 1.10 2017/04/30 01:21:59 ryoon Exp $

MODNAME=		oauth
PECL_VERSION=		2.0.1
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP oauth consumer extension
PKGREVISION=		3
LICENSE=		modified-bsd

PHP_VERSIONS_ACCEPTED=	70

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.41 2025/03/05 15:17:10 taca Exp $

MODNAME=		oauth
PECL_VERSION=		2.0.9
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2008/06/12 00:47:05 obache Exp $

MODNAME=		ming
CATEGORIES+=		multimedia

MAINTAINER=		obache@NetBSD.org
COMMENT=		PHP extension for Ming library

CONFLICTS=	php-ming-[0-9]*

PHP_VERSIONS_ACCEPTED=	5

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:38 joerg Exp $

MODNAME=		ming
CATEGORIES+=		multimedia

MAINTAINER=		obache@NetBSD.org
COMMENT=		PHP extension for Ming library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-ming-[0-9]*

PHP_VERSIONS_ACCEPTED=	5

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

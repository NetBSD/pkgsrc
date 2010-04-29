# $NetBSD: Makefile,v 1.9 2010/04/29 04:55:25 obache Exp $

MODNAME=		ming
PKGREVISION=		1
CATEGORIES+=		multimedia

MAINTAINER=		obache@NetBSD.org
COMMENT=		PHP extension for Ming library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-ming-[0-9]*

PHP_VERSIONS_ACCEPTED=	52

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2011/01/13 13:38:57 wiz Exp $

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

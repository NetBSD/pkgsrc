# $NetBSD: Makefile,v 1.1.1.1 2010/03/16 15:39:10 taca Exp $

MODNAME=		intl
CATEGORIES+=		misc
COMMENT=		PHP extension for internationalization support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared
CONFIGURE_ARGS+=	--with-icu-dir=${BUILDLINK_PREFIX.icu}

PHP_VERSION_REQD=	53

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

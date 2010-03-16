# $NetBSD: Makefile,v 1.10 2010/03/16 11:56:22 taca Exp $

MODNAME=		dbase
CATEGORIES+=		databases
COMMENT=		PHP extension for dBase database access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-dbase-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

PHP_VERSION_REQD=	5

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

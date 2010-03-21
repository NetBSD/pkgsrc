# $NetBSD: Makefile,v 1.11 2010/03/21 11:20:41 jdolecek Exp $

MODNAME=		dbase
CATEGORIES+=		databases
COMMENT=		PHP extension for dBase database access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-dbase-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

PHP_VERSIONS_ACCEPTED=	52

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:19 joerg Exp $

MODNAME=		dbase
CATEGORIES+=		databases
COMMENT=		PHP extension for dBase database access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-dbase-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		dbase
CATEGORIES+=		databases
COMMENT=		PHP extension for dBase database access

CONFLICTS=	php-dbase-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.11 2010/01/29 17:28:52 joerg Exp $

MODNAME=		mssql
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

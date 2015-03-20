# $NetBSD: Makefile,v 1.19 2015/03/20 16:33:28 taca Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

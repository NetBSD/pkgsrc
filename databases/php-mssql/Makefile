# $NetBSD: Makefile,v 1.45 2024/11/01 00:51:03 wiz Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases
PKGREVISION=		14

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

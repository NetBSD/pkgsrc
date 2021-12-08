# $NetBSD: Makefile,v 1.38 2021/12/08 16:03:41 adam Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases
PKGREVISION=		7

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

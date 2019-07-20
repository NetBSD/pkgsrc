# $NetBSD: Makefile,v 1.32 2019/07/20 22:46:13 wiz Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases
PKGREVISION=		1

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

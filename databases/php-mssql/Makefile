# $NetBSD: Makefile,v 1.50 2026/01/07 08:46:13 wiz Exp $

MODNAME=		mssql
PKGREVISION=		19
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-mssql-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

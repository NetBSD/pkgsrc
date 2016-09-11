# $NetBSD: Makefile,v 1.24 2016/09/11 17:03:25 taca Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-mysql-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
USE_PHP_EXT_PATCHES=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mysql
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
.else
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif
CONFIGURE_ENV+=		CPP=${CPP:Q}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

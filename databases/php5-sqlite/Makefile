# $NetBSD: Makefile,v 1.2 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP5 extension for SQLite database engine

MAINTAINER=		jdolecek@NetBSD.org

USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=        --with-${MODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

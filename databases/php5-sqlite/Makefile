# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:14 tv Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP5 extension for SQLite database engine

MAINTAINER=		jdolecek@NetBSD.org


CONFIGURE_ARGS+=        --with-${MODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 22:11:52 jdolecek Exp $

MODNAME=		sqlite
CATEGORIES+=		databases
COMMENT=		PHP5 extension for SQLite database engine

MAINTAINER=		jdolecek@NetBSD.org

USE_BUILDLINK3=		yes

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=        --with-${MODNAME}=shared,${BUILDLINK_PREFIX.sqlite}

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

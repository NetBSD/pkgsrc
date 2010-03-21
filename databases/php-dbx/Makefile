# $NetBSD: Makefile,v 1.10 2010/03/21 11:20:41 jdolecek Exp $

MODNAME=		dbx
PECL_VERSION=		1.1.0
CATEGORIES+=		databases
COMMENT=		PHP database abstraction layer extension

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		jdolecek@NetBSD.org

CONFLICTS=	php-dbx-[0-9]*

PHP_VERSIONS_ACCEPTED=	52

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

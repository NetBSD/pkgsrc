# $NetBSD: Makefile,v 1.9 2010/03/16 11:56:22 taca Exp $

MODNAME=		dbx
PECL_VERSION=		1.1.0
CATEGORIES+=		databases
COMMENT=		PHP database abstraction layer extension

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		jdolecek@NetBSD.org

CONFLICTS=	php-dbx-[0-9]*

#
# can't catch up with PHP 5.3.
#
PHP_VERSION_REQD=	5

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

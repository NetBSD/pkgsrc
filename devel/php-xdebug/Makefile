# $NetBSD: Makefile,v 1.18 2017/12/06 22:05:05 jdolecek Exp $
#

MODNAME=		xdebug
PECL_VERSION=		2.5.5
CATEGORIES=		devel
MASTER_SITES=		http://xdebug.org/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php

PHP_ZEND_EXTENSION=	yes

# XXX add 72 and remove 56 when this package would be updated to final 2.6.0
# XXX use php-xdebug-devel for now if you need 72
PHP_VERSIONS_ACCEPTED=  56 70 71

CONFLICTS=		${PHP_PKG_PREFIX}-xdebug>=2.5.99

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2018/01/31 21:14:12 jdolecek Exp $
#

MODNAME=		xdebug
PECL_VERSION=		2.6.0
CATEGORIES=		devel
MASTER_SITES=		http://xdebug.org/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php

PHP_ZEND_EXTENSION=	yes

# support for 5.5 and 5.6 dropped in 2.6.0
PHP_VERSIONS_ACCEPTED=  70 71 72

CONFLICTS=		${PHP_PKG_PREFIX}-xdebug<2.6.0

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

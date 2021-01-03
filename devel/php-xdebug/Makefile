# $NetBSD: Makefile,v 1.34 2021/01/03 07:28:56 taca Exp $
#

MODNAME=		xdebug
PECL_VERSION=		3.0.1
CATEGORIES=		devel
MASTER_SITES=		http://xdebug.org/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		https://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php

PHP_ZEND_EXTENSION=	yes

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

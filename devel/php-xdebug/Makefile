# $NetBSD: Makefile,v 1.31 2020/06/13 16:06:19 taca Exp $
#

MODNAME=		xdebug
PECL_VERSION=		2.9.6
CATEGORIES=		devel
MASTER_SITES=		http://xdebug.org/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		https://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php

PHP_ZEND_EXTENSION=	yes

PHP_VERSIONS_ACCEPTED=	72 73 74

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

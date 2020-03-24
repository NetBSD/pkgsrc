# $NetBSD: Makefile,v 1.29 2020/03/24 15:01:55 taca Exp $
#

MODNAME=		xdebug
PECL_VERSION=		2.9.4
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

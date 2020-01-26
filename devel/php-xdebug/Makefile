# $NetBSD: Makefile,v 1.27 2020/01/26 17:31:02 rillig Exp $
#

MODNAME=		xdebug
PECL_VERSION=		2.9.0
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

# $NetBSD: Makefile,v 1.43 2022/12/14 11:46:41 wiz Exp $

MODNAME=		xdebug
PECL_VERSION=		3.1.6
CATEGORIES=		devel
EXTRACT_SUFX=		.tgz

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		https://xdebug.org/
COMMENT=		PHP extension for debugging
LICENSE=		php

PHP_ZEND_EXTENSION=	yes

PHP_VERSIONS_INCOMPATIBLE=	56 82

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

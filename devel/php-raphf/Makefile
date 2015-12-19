# $NetBSD: Makefile,v 1.4 2015/12/19 14:27:13 taca Exp $

MODNAME=	raphf
PECL_VERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	55 56

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/php/ext/raphf
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_raphf.h \
		${DESTDIR}${PREFIX}/include/php/ext/raphf

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

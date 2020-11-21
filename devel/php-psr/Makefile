# $NetBSD: Makefile,v 1.1 2020/11/21 13:49:50 otis Exp $

MODNAME=	psr
PECL_VERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/psr
COMMENT=	Provide the accepted PSR interfaces for other extensions
LICENSE=	2-clause-bsd

PHP_VERSIONS_ACCEPTED=	72 73 74

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	include/php/ext/psr
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_psr.h \
		${DESTDIR}${PREFIX}/include/php/ext/psr

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

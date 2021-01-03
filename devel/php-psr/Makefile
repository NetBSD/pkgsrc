# $NetBSD: Makefile,v 1.3 2021/01/03 16:06:57 taca Exp $

MODNAME=	psr
PECL_VERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/psr
COMMENT=	Provide the accepted PSR interfaces for other extensions
LICENSE=	2-clause-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	include/php/ext/psr
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_psr.h \
		${DESTDIR}${PREFIX}/include/php/ext/psr

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

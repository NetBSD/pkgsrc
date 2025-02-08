# $NetBSD: Makefile,v 1.12 2025/02/08 03:41:14 taca Exp $

MODNAME=	raphf
PECL_VERSION=	2.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	74 81 82 83

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/raphf
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_raphf.h \
		${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/raphf
	${INSTALL_DATA} ${WRKSRC}/src/php_raphf_api.h \
		${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/raphf

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

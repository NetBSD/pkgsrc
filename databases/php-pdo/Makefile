# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

MODNAME=		PDO
PKGMODNAME=		pdo
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PKGREVISION=		# empty
PECL_VERSION=		1.0RC1
CATEGORIES+=		databases
MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		PHP extension for PHP Data Objects (base)

CONFIGURE_ARGS+=	--with-${PKGMODNAME}

PHP_VERSION_REQD=	5

PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/php/ext/pdo
	for inc in ${PDO_INCLUDES}; do	\
		${INSTALL_DATA} ${WRKSRC}/$$inc ${PREFIX}/include/php/ext/pdo/$$inc;\
	done

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

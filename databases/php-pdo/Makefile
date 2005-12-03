# $NetBSD: Makefile,v 1.2 2005/12/03 17:24:28 jdolecek Exp $

PDO_DRIVER=		# empty
PDO_VERSION=		1.0.2

.include "../../databases/php-pdo/module.mk"

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

# $NetBSD: Makefile,v 1.6 2006/06/02 18:27:55 joerg Exp $

PDO_DRIVER=		# empty
PDO_VERSION=		1.0.2

PHP_VERSIONS_ACCEPTED=	5

.include "../../databases/php-pdo/module.mk"

COMMENT=		PHP extension for PHP Data Objects (base)

CONFIGURE_ARGS+=	--with-${PKGMODNAME}

PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/php/ext/pdo
.for inc in ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc:Q} ${PREFIX}/include/php/ext/pdo/${inc:Q}
.endfor

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

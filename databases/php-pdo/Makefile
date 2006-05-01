# $NetBSD: Makefile,v 1.4 2006/05/01 13:52:55 rillig Exp $

PDO_DRIVER=		# empty
PDO_VERSION=		1.0.2

.include "../../databases/php-pdo/module.mk"

COMMENT=		PHP extension for PHP Data Objects (base)
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-${PKGMODNAME}

PHP_VERSION_REQD=	5

PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/php/ext/pdo
.for inc ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc:Q} ${PREFIX}/include/php/ext/pdo/${inc:Q}
.endfor

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

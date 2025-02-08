# $NetBSD: Makefile,v 1.16 2025/02/08 03:10:22 taca Exp $

MODNAME=		pdo
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (base)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h php_pdo_error.h
PLIST_VARS+=		pdo_error
PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

post-install:
.for inc in ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc} ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/pdo/${inc}
.endfor

.include "../../mk/bsd.pkg.mk"

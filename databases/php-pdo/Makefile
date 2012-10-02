# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:39 asau Exp $

MODNAME=		pdo
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (base)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}

INSTALLATION_DIRS+=	include/php/ext/pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h
PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

post-install:
.for inc in ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc} ${DESTDIR}${PREFIX}/include/php/ext/pdo/${inc}
.endfor

.include "../../mk/bsd.pkg.mk"

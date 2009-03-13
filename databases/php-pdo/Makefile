# $NetBSD: Makefile,v 1.8 2009/03/13 10:57:20 sborrill Exp $

MODNAME=		pdo
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (base)

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"
# Remove the following line when PHP >= 5.2.10 is released
.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}

INSTALLATION_DIRS+=	include/php/ext/pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h
PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

post-install:
.for inc in ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc} ${DESTDIR}${PREFIX}/include/php/ext/pdo/${inc}
.endfor
	
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:19 joerg Exp $

PDO_DRIVER=		# empty
PDO_VERSION=		1.0.2

PHP_VERSIONS_ACCEPTED=	5

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/php-pdo/module.mk"

COMMENT=		PHP extension for PHP Data Objects (base)

CONFIGURE_ARGS+=	--with-${PKGMODNAME}

PLIST_SRC+=		${.CURDIR}/../../databases/php-pdo/PLIST.pdo

PDO_INCLUDES=		php_pdo_driver.h php_pdo.h

INSTALLATION_DIRS+=	include/php/ext/pdo

post-install:
.for inc in ${PDO_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${inc} ${DESTDIR}${PREFIX}/include/php/ext/pdo/${inc}
.endfor

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

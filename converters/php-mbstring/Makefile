# $NetBSD: Makefile,v 1.12 2025/02/08 03:07:01 taca Exp $

MODNAME=		mbstring
PKGREVISION=		1
CATEGORIES+=		converters
COMMENT=		PHP extension for multibyte characters support
LICENSE=		php

CONFLICTS=		php-mbstring-[0-9]*

INSTALLATION_DIRS+=	${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/filters
INSTALLATION_DIRS+=	${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/mbfl
INSTALLATION_DIRS+=	${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/nls

PLIST_SRC+=		${.CURDIR}/PLIST.php${PHP_VER}

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/libmbfl/filters/*.h ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/filters
	${INSTALL_DATA} ${WRKSRC}/libmbfl/mbfl/*.h ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/mbfl
	${INSTALL_DATA} ${WRKSRC}/libmbfl/nls/*.h ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/mbstring/libmbfl/nls

.include "../../lang/php/ext.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

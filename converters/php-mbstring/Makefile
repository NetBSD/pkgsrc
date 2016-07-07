# $NetBSD: Makefile,v 1.4 2016/07/07 13:59:00 jperkin Exp $

MODNAME=		mbstring
PKGREVISION=		1
CATEGORIES+=		converters
COMMENT=		PHP extension for multibyte characters support
LICENSE=		php

CONFLICTS=		php-mbstring-[0-9]*

INSTALLATION_DIRS+=	${PREFIX}/include/php/ext/mbstring/libmbfl/filters
INSTALLATION_DIRS+=	${PREFIX}/include/php/ext/mbstring/libmbfl/mbfl
INSTALLATION_DIRS+=	${PREFIX}/include/php/ext/mbstring/libmbfl/nls

PLIST_SRC+=		${.CURDIR}/PLIST

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/libmbfl/filters/*.h ${DESTDIR}${PREFIX}/include/php/ext/mbstring/libmbfl/filters
	${INSTALL_DATA} ${WRKSRC}/libmbfl/mbfl/*.h ${DESTDIR}${PREFIX}/include/php/ext/mbstring/libmbfl/mbfl
	${INSTALL_DATA} ${WRKSRC}/libmbfl/nls/*.h ${DESTDIR}${PREFIX}/include/php/ext/mbstring/libmbfl/nls

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

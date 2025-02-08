# $NetBSD: Makefile,v 1.4 2025/02/08 03:44:47 taca Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		${PHP_PKG_PREFIX}-vmailmgr-${VERSION}
PKGREVISION=		1
CATEGORIES=		mail

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (PHP bindings)
LICENSE=		gnu-gpl-v2

DEPENDS+=		php${PHP_VER}>=${PHP_BASE_VERS}:${PHPPKGSRCDIR}

CONFLICTS+=		php-vmailmgr-[0-9]*

CONFIGURE_ARGS+=	--enable-php

BUILD_DIRS=		php
INSTALL_DIRS=		php

post-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_DIRS}/vmail.features \
		${DESTDIR}${PREFIX}/share/vmailmgr/php/README
	${MV} ${DESTDIR}${PREFIX}/share/vmailmgr/php \
		${DESTDIR}${PREFIX}/share/vmailmgr/${PHP_PKG_PREFIX}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"

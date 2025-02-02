# $NetBSD: Makefile,v 1.2 2025/02/02 11:37:30 wiz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		${PHP_PKG_PREFIX}-vmailmgr-${VERSION}
CATEGORIES=		mail

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (PHP bindings)
LICENSE=		gnu-gpl-v2

DEPENDS+=		php-[0-9]*:${PHPPKGSRCDIR}

CONFIGURE_ARGS+=	--enable-php

BUILD_DIRS=		php
INSTALL_DIRS=		php

CONFLICTS+=		php-vmailmgr-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_DIRS}/vmail.features \
		${DESTDIR}${PREFIX}/share/vmailmgr/php/README

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"

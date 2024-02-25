# $NetBSD: Makefile,v 1.1 2024/02/25 12:09:20 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		php-vmailmgr-${VERSION}
CATEGORIES=		mail

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (PHP bindings)
LICENSE=		gnu-gpl-v2

DEPENDS+=		php-[0-9]*:${PHPPKGSRCDIR}

CONFIGURE_ARGS+=	--enable-php

BUILD_DIRS=		php
INSTALL_DIRS=		php

post-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_DIRS}/vmail.features \
		${DESTDIR}${PREFIX}/share/vmailmgr/php/README

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"

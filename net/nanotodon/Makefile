# $NetBSD: Makefile,v 1.28 2025/01/11 14:43:31 tsutsui Exp $

DISTNAME=	nanotodon-0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=taka-tuos/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/taka-tuos/nanotodon
COMMENT=	CUI/C99 mastodon client
LICENSE=	mit

USE_LANGUAGES=		c

# error: 'for' loop initial declaration used outside C99 mode
FORCE_C_STD=		gnu99
USE_CC_FEATURES=	c99

INSTALLATION_DIRS+=	bin share/doc/nanotodon

BUILD_TARGET=		default

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nanotodon ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/share/doc/nanotodon

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

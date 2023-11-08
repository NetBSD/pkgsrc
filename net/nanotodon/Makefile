# $NetBSD: Makefile,v 1.16 2023/11/08 13:20:31 wiz Exp $

GITHUB_TAG=	0.3.1
DISTNAME=	nanotodon-${GITHUB_TAG}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=taka-tuos/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/taka-tuos/nanotodon
COMMENT=	CUI/C99 mastodon client
LICENSE=	mit

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin share/doc/nanotodon

BUILD_TARGET=		default
MAKE_FILE=		Makefile.bsd

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing hardcoded paths and link options in Makefiles.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile.bsd
SUBST_SED.prefix+=	-e 's|/usr/pkg/|${PREFIX}/|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nanotodon ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/share/doc/nanotodon

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

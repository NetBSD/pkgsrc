# $NetBSD: Makefile,v 1.18 2024/05/06 08:27:54 jperkin Exp $

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
MAKE_FILE=		Makefile.base
MAKE_FLAGS+=		NCURSES=ncursesw

# problems rendering UTF-8
#MAKE_FLAGS+=		NCURSES=${BUILDLINK_LIBNAME.curses}
#FAKE_NCURSES=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nanotodon ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/share/doc/nanotodon

.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
# problems rendering UTF-8
#.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

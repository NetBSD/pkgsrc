# $NetBSD: Makefile,v 1.1 2026/11/08 16:40:18 ryoon Exp $

DISTNAME=	raygui-5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=raysan5/}
GITHUB_PROJECT=	raygui
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/raysan5/raygui/
COMMENT=	Simple and easy-to-use immediate-mode gui library
LICENSE=	zlib

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	include

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/raygui.h \
		${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"

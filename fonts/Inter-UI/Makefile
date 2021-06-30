# $NetBSD: Makefile,v 1.4 2021/06/30 08:52:47 fcambus Exp $

VERSION=	3.19
DISTNAME=	Inter-${VERSION}
PKGNAME=	Inter-UI-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsms/}
GITHUB_TAG=	v${VERSION}
GITHUB_PROJECT=	inter

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rsms.me/inter/
COMMENT=	Font for highly legible text on computer screens
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:tl}

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	pwd
	${INSTALL_DATA} ${WRKSRC}/docs/font-files/*.otf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2022/03/30 13:56:02 wiz Exp $

DISTNAME=	Selawik_Release
PKGNAME=	selawik-ttf-1.01
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_PROJECT=	Selawik
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/Selawik/
COMMENT=	Open source replacement for Segoe UI
LICENSE=	ofl-v1.1


WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*ttf ${DESTDIR}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2023/03/28 13:21:07 joerg Exp $
#

DISTNAME=	Amiri-1.000
PKGNAME=	amiri-ttf-1.000
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=aliftype/}
GITHUB_PROJECT=	amiri
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.amirifont.org/
COMMENT=	Classic Arabic typeface in Nasksh style
LICENSE=	ofl-v1.1


NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

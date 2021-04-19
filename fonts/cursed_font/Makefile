# $NetBSD: Makefile,v 1.1 2021/04/19 16:03:10 nia Exp $

DISTNAME=	cursed-0.1.0
PKGNAME=	${DISTNAME:S/cursed-/cursed_font-/1}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiedtl/}
GITHUB_PROJECT=	cursed
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://tilde.team/~kiedtl/projects/cursed/
COMMENT=	9x18 bitmapped font designed for low-DPI screens
LICENSE=	cc-by-v4.0

NO_BUILD=	yes
USE_LANGUAGES=	# none

FONTS_DIRS.x11=	cursed

INSTALLATION_DIRS+=	share/fonts/X11/BDF
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/font.bdf \
		${DESTDIR}${PREFIX}/share/fonts/X11/BDF/cursed.bdf
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/demo.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"

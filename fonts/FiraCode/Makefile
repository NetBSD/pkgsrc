# $NetBSD: Makefile,v 1.8 2024/05/17 13:24:08 pho Exp $

DISTNAME=	Fira_Code_v6.2
PKGNAME=	${DISTNAME:S/Fira_Code_v/FiraCode-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=tonsky/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tonsky/FiraCode/
COMMENT=	Monospaced font with programming ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=		# none
NO_BUILD=		yes
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf		${DESTDIR}${PREFIX}/share/fonts/X11/TTF
	${INSTALL_DATA} ${WRKSRC}/variable_ttf/*.ttf	${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"

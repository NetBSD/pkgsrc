# $NetBSD: Makefile,v 1.2 2022/01/25 02:04:43 wiz Exp $

DISTNAME=	JetBrainsMono-2.242
PKGNAME=	${DISTNAME:S/Mono/Mono-ttf/}
CATEGORIES=	fonts
#MASTER_SITES=	${MASTER_SITE_GITHUB:=JetBrains/}
#GITHUB_RELEASE=	v${PKGVERSION_NOREV}
MASTER_SITES+=	https://download.jetbrains.com/fonts/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jetbrains.com/lp/mono/
COMMENT=	Free and open-source typeface for developers
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/fonts
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-build:
do-install:
	${INSTALL_DATA} ${WRKSRC}/ttf/*ttf ${DESTDIR}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

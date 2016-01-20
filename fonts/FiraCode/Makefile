# $NetBSD: Makefile,v 1.1 2016/01/20 11:38:44 wiz Exp $

DISTNAME=	FiraCode_1.102
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=tonsky/}
GITHUB_RELEASE=	${DISTNAME:S/FiraCode_//}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tonsky/FiraCode/
COMMENT=	Monospaced font with programming ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2019/11/02 22:24:38 rillig Exp $

DISTNAME=	Hasklig-1.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=i-tu/}
GITHUB_RELEASE=	${DISTNAME:S/Hasklig-//}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/i-tu/Hasklig/
COMMENT=	Code font with monospaced ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

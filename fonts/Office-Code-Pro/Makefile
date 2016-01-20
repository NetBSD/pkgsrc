# $NetBSD: Makefile,v 1.1 2016/01/20 11:37:52 wiz Exp $

DISTNAME=	Office-Code-Pro-1.004
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=nathco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nathco/Office-Code-Pro/
COMMENT=	Customized version of Source Code Pro
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/Fonts/*/OTF/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

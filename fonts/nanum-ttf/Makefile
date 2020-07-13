# $NetBSD: Makefile,v 1.6 2020/07/13 16:59:59 minskim Exp $

DISTNAME=	fonts-nanum_${PKGVERSION_NOREV}.orig
PKGNAME=	nanum-ttf-20200506
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fonts-nanum/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://hangeul.naver.com/
COMMENT=	Korean fonts distributed by Naver
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fonts-nanum-${PKGVERSION_NOREV}

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

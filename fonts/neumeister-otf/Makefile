# $NetBSD: Makefile,v 1.3 2022/01/31 14:44:35 wiz Exp $

DISTNAME=	neumeister-1000
PKGNAME=	neumeister-otf-0.0.2021.11.07
CATEGORIES=	fonts
MASTER_SITES=	# https://typography.guru/forums/topic/138055-fdi-neumeister-free-font-download/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fdi-type.de/fonts/neumeister/
COMMENT=	FDI Neumeister, a modern fraktur font
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/OTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKDIR}/*.otf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2021/12/16 13:44:49 wiz Exp $

DISTNAME=	altmeister
PKGNAME=	altmeister-otf-0.0.2021.11.07
CATEGORIES=	fonts
MASTER_SITES=	# https://typography.guru/forums/topic/136924-fdi-altmeister-free-font-download/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fdi-type.de/fonts/fdi-altmeister/
COMMENT=	FDI Altmeister, a modern fraktur font
LICENSE=	ofl-v1.1

INTERACTIVE_STAGE=	fetch
FETCH_MESSAGE=		"Please visit the homepage ${HOMEPAGE}"
FETCH_MESSAGE+=		"and download the file ${DISTNAME}${EXTRACT_SUFX} from the typeguru download link"
FETCH_MESSAGE+=		"and save it in the ${_DISTDIR} directory"

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/OTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKDIR}/*.otf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"

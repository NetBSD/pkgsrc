# $NetBSD: Makefile,v 1.3 2025/05/05 18:37:13 vins Exp $

DISTNAME=	suxus-1.5
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://oldhome.schmorp.de/marc/data/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.gz
DISTFILES=	suxus-iso-8859-1.bdf.gz \
		suxus-iso-8859-15.bdf.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oldhome.schmorp.de/marc/suxus.html
COMMENT=	Readable bitmap font for low-res displays
LICENSE=	public-domain

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTS=		suxus-iso-8859-1 suxus-iso-8859-15
FONTDIR=	share/fonts/X11/PCF

REQD_DIRS=	${FONTDIR}
FONTS_DIRS.x11=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}

WRKSRC=		${WRKDIR}

do-build:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in ${FONTS}; do			\
	  bdftopcf $${FONT}.bdf |			\
		${GZIP_CMD} -c >$${FONT}.pcf.gz;	\
	done

do-install:
	${RUN}for FONT in ${FONTS}; do			\
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz	\
		${DESTDIR}${PREFIX}/${FONTDIR};		\
	done

.include "../../mk/bsd.pkg.mk"

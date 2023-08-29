# $NetBSD: Makefile,v 1.1 2023/08/29 05:58:08 vins Exp $

DISTNAME=	suxus-1.5
CATEGORIES=	fonts
MASTER_SITES=	http://oldhome.schmorp.de/marc/data/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.gz
DISTFILES=	suxus-iso-8859-1.bdf.gz \
		suxus-iso-8859-15.bdf.gz \
		fonts.alias

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://oldhome.schmorp.de/marc/suxus.html
COMMENT=	Readable bitmap font for low-res displays
LICENSE=	public-domain

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTS=		suxus-iso-8859-1 suxus-iso-8859-15
FONTDIR=	share/fonts/X11/${PKGBASE}
REQD_DIRS=	${FONTDIR}
FONTS_DIRS.x11=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}
MESSAGE_SUBST+=		FONTDIR=${FONTDIR:Q}

WRKSRC=		${WRKDIR}

do-build:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in ${FONTS}; do			\
	  ${ECHO_N} "Compiling font $${FONT} ... ";	\
	  bdftopcf $${FONT}.bdf |			\
		${GZIP_CMD} -c >$${FONT}.pcf.gz;	\
	  ${ECHO} "done";				\
	done

do-install:
	${RUN}for FONT in ${FONTS}; do			\
	  ${ECHO_N} "Installing font $${FONT} ... ";	\
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz	\
		${DESTDIR}${PREFIX}/${FONTDIR};		\
	  ${ECHO} "done";				\
	done

post-install:
	${RUN}${ECHO_N} "Installing font aliases ... ";	\
	${INSTALL_DATA} ${WRKDIR}/fonts.alias		\
	  ${DESTDIR}${PREFIX}/${FONTDIR};

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2023/10/01 13:57:49 vins Exp $

PKGNAME=	leahfonts-20170708
CATEGORIES=	fonts
MASTER_SITES=	https://git.vuxu.org/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

DISTFILES=			5x13-master.tar.xz sq-master.tar.xz \
				smalltalk10.bdf
SITES.5x13-master.tar.xz=	${MASTER_SITES}/5x13/snapshot/
SITES.sq-master.tar.xz=		${MASTER_SITES}/sq/snapshot/
SITES.smalltalk10.bdf=		https://leahneukirchen.org/fonts/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://leahneukirchen.org/fonts/
COMMENT=	Bitmap fonts by Leah Neukirchen
LICENSE=	public-domain

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTS=		5x13 smalltalk10 sq sqb
FONTDIR=	share/fonts/X11/${PKGBASE}
REQD_DIRS=	${FONTDIR}
FONTS_DIRS.x11=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}
MESSAGE_SUBST+=		FONTDIR=${FONTDIR:Q}

post-extract:
	${RUN}${MKDIR} ${WRKDIR}/${PKGNAME_NOREV}
	${RUN}cd ${WRKDIR} &&				\
	for FONT in smalltalk10 5x13-master/5x13	\
	  sq-master/sq sq-master/sqb; do		\
	  ${MV} $${FONT}.bdf ${WRKSRC};			\
	done

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
	${INSTALL_DATA} ${FILESDIR}/fonts.alias		\
  		${DESTDIR}${PREFIX}/${FONTDIR};

.include "../../mk/bsd.pkg.mk"

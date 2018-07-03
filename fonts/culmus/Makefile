# $NetBSD: Makefile,v 1.1 2018/07/03 06:00:25 maya Exp $

DISTNAME=	culmus-0.132
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=culmus/}

MAINTAINER=	maya@NetBSD.org
HOMEPAGE=	http://culmus.sourceforge.net/
COMMENT=	Culmus Hebrew fonts
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
NO_BUILD=	yes

TTF_FONTS_DIR=		${PREFIX}/share/fonts/X11/TTF
OTF_FONTS_DIR=		${PREFIX}/share/fonts/X11/OTF

INSTALLATION_DIRS=	${TTF_FONTS_DIR} ${OTF_FONTS_DIR}

do-install:
	for font in `find ${WRKSRC} -name '*.ttf'`; \
	do \
		${INSTALL_DATA} $${font} ${DESTDIR}${TTF_FONTS_DIR}; \
	done; \
	for font in `find ${WRKSRC} -name '*.otf'`; \
	do \
		${INSTALL_DATA} $${font} ${DESTDIR}${OTF_FONTS_DIR}; \
	done;

.include "../../mk/bsd.pkg.mk"

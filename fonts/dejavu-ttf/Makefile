# $NetBSD: Makefile,v 1.1.1.1 2005/09/07 22:40:23 reed Exp $

DISTNAME=	dejavu-ttf-1.13
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}

MAINTAINER=	jakollasch@keymaster.madscientistresearch.net
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/dejavu-ttf

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm *.ttf ${PREFIX}/lib/X11/fonts/TTF/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS LICENSE NEWS README \
		${PREFIX}/share/doc/dejavu-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"

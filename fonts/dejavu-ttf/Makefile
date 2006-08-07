# $NetBSD: Makefile,v 1.5 2006/08/07 14:41:10 wiz Exp $
#

DISTNAME=	dejavu-ttf-2.8
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}

MAINTAINER=	jakollasch@keymaster.madscientistresearch.net
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf+=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/dejavu-ttf

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm *.ttf ${PREFIX}/lib/X11/fonts/TTF/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS LICENSE NEWS README \
		${PREFIX}/share/doc/dejavu-ttf

.include "../../mk/bsd.pkg.mk"

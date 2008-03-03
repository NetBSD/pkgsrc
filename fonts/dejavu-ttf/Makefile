# $NetBSD: Makefile,v 1.8 2008/03/03 20:17:12 jlam Exp $
#

DISTNAME=	dejavu-ttf-2.21
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf+=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/dejavu-ttf

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm *.ttf \
		${DESTDIR}${PREFIX}/lib/X11/fonts/TTF/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS LICENSE NEWS README \
		${DESTDIR}${PREFIX}/share/doc/dejavu-ttf

.include "../../mk/bsd.pkg.mk"

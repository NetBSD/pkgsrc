# $NetBSD: Makefile,v 1.10 2008/09/10 00:27:12 jakllsch Exp $
#

DISTNAME=	dejavu-fonts-ttf-2.26
PKGNAME=        ${DISTNAME:S/fonts-//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dejavu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://dejavu.sourceforge.net/
COMMENT=	DejaVu family of TrueType fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

FONTS_DIRS.ttf+=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/dejavu-ttf

do-install:
	cd ${WRKSRC}/ttf && pax -rw -pm *.ttf \
		${DESTDIR}${PREFIX}/lib/X11/fonts/TTF/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS LICENSE NEWS README \
		${DESTDIR}${PREFIX}/share/doc/dejavu-ttf

.include "../../mk/bsd.pkg.mk"

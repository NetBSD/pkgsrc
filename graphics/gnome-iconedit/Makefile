# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:36 jlam Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@netbsd.org
COMMENT=		icon editor based on GNOME libraries

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf
DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs
DEPENDS+=		oaf>=0.6.0:../../devel/oaf

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_X11BASE=		YES

# for finding libpng
CPPFLAGS+=		-I${LOCALBASE}/include

post-configure:
	cd ${WRKSRC}/src && ${GMAKE} clean

.include "../../mk/bsd.pkg.mk"

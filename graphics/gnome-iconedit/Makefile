# $NetBSD: Makefile,v 1.1.1.1 2000/12/03 15:07:23 wiz Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@netbsd.org

DEPENDS+=		gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf
DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs
DEPENDS+=		oaf-0.6.0:../../devel/oaf
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_X11BASE=		YES

# for finding libpng
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

post-configure:
	cd ${WRKSRC}/src && ${GMAKE} clean

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.19 2004/02/26 16:25:52 cube Exp $
#

DISTNAME=		anjuta-1.2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=anjuta/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.anjuta.org/
COMMENT=		Gnome based IDE for C and C++

DEPENDS+=		autoconf>=2.59:../../devel/autoconf
DEPENDS+=		automake>=1.8.2:../../devel/automake
DEPENDS+=		gdk-pixbuf>=0.22:../../graphics/gdk-pixbuf
DEPENDS+=		gettext>=0.11.5:../../devel/gettext
DEPENDS+=		glade2>=2.0.1:../../devel/glade2
DEPENDS+=		gmake>=3.80:../../devel/gmake
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		gnome2-terminal>=2.4.2:../../x11/gnome2-terminal
DEPENDS+=		libtool>=1.5.2:../../devel/libtool
DEPENDS+=		pkgconfig>=0.15.0:../../devel/pkgconfig
DEPENDS+=		yelp>=2.4.2:../../misc/yelp

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=        --localstatedir=${LOCALSTATEDIR}

# Build system adds the last component ('/scrollkeeper')
LOCALSTATEDIR=          ${SCROLLKEEPER_DATADIR:H}

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

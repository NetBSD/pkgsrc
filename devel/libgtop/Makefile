# $NetBSD: Makefile,v 1.8 1999/01/02 19:50:17 tron Exp $
#

DISTNAME=	libgtop-0.99.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-0.99.0:../../x11/gnome-libs
DEPENDS+=	guile-1.3:../../lang/guile
DEPENDS+=	gettext-0.10.35:../../devel/gettext

CONFLICTS=	libgtop-*

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"  \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

LDFLAGS+=		-L${LOCALBASE}/lib -lintl

.include "../../mk/bsd.pkg.mk"

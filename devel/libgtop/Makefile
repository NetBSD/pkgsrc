# $NetBSD: Makefile,v 1.12 1999/03/07 19:50:55 tron Exp $
#

DISTNAME=	libgtop-1.0.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gnome-libs-1.0.1:../../x11/gnome-libs
DEPENDS+=	guile-1.3:../../lang/guile

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
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

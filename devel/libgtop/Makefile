# $NetBSD: Makefile,v 1.20 1999/08/22 22:02:32 tron Exp $
#

DISTNAME=		libgtop-1.0.1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gettext-0.10.35:../../devel/gettext \
			gnome-libs-1.0.5:../../x11/gnome-libs \
			guile-1.3:../../lang/guile

NOT_FOR_PLATFORM=	*-*-alpha	# problems with gtk

GNU_CONFIGURE=
USE_X11BASE=
USE_GMAKE=
USE_LIBTOOL=

IGNORE=			"got broken by removal of Mach VM"

CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"  \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

LDFLAGS+=		-L${LOCALBASE}/lib -lintl

.include "../../mk/bsd.pkg.mk"

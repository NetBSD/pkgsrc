# $NetBSD: Makefile,v 1.21 1999/08/30 08:54:03 jlam Exp $
#

DISTNAME=		libgtop-1.0.2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.home-of-linux.org/gnome/libgtop/

DEPENDS+=		gettext-0.10.35:../../devel/gettext
DEPENDS+=		gnome-libs-1.0.14:../../x11/gnome-libs
DEPENDS+=		guile-1.3.2:../../lang/guile

NOT_FOR_PLATFORM=	*-*-alpha	# problems with gtk

IGNORE=			"got broken by removal of Mach VM"

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -lintl

# The following CPPFLAGS are for debugging purposes.
CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS

CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"  \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"

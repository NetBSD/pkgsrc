# $NetBSD: Makefile,v 1.9 2000/11/26 19:55:39 mycroft Exp $
#

DISTNAME=		gdk-pixbuf-0.9.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gdk-pixbuf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
DEPENDS+=		gnome-libs>=1.0.53:../../x11/gnome-libs

USE_GMAKE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

pre-configure:
	cd ${WRKSRC} && ${SETENV} automake

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/libart.m4 \
		${LOCALBASE}/share/aclocal/libart.m4

.include "../../mk/bsd.pkg.mk"

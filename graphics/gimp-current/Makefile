# $NetBSD: Makefile,v 1.6 2000/03/02 02:12:07 hubertf Exp $

DISTNAME=		gimp-1.1.13
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.13/ \
			ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/unstable/v1.1.13/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/unstable/v1.1.13/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=		png>=1.0.3:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		gettext-0.10.*:../../devel/gettext

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE} \
			--disable-perl \
			--disable-python
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" INTLLIBS="-lintl"

CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-E
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gimp.m4 \
	  ${LOCALBASE}/share/aclocal/gimp.m4

.include "../../mk/bsd.pkg.mk"

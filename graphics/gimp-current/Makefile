# $NetBSD: Makefile,v 1.7 2000/03/02 09:39:05 tron Exp $

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
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == ELF)
LDFLAGS+=		-Wl,-E
.endif

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gimp.m4 \
	  ${LOCALBASE}/share/aclocal/gimp.m4

.include "../../mk/bsd.pkg.mk"

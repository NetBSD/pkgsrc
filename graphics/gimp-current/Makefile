# $NetBSD: Makefile,v 1.10 2000/03/14 18:12:16 tron Exp $

DISTNAME=		gimp-1.1.18
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.18/ \
			ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v1.1.18/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/unstable/v1.1.18/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gimp.org/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gtk+>=1.2.7:../../x11/gtk
DEPENDS+=		mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=		png>=1.0.3:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE} \
			--disable-perl \
			--disable-python
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" INTLLIBS="-lintl" \
			GNOME_CONFIG=no

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

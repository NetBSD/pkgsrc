# $NetBSD: Makefile,v 1.28 2001/02/16 15:22:22 wiz Exp $

DISTNAME=		gimp-1.1.29
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.29/ \
			ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v1.1.29/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/unstable/v1.1.29/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs
DEPENDS+=		mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_X11BASE=		YES
USE_XPM=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}" \
			--disable-perl \
			--disable-python
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" GNOME_CONFIG=no

CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gimp.m4 \
	  ${LOCALBASE}/share/aclocal/gimp.m4

.include "../../mk/bsd.pkg.mk"

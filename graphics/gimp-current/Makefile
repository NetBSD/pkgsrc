# $NetBSD: Makefile,v 1.24 2000/08/23 23:14:28 tron Exp $

DISTNAME=		gimp-1.1.24
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.24/ \
			ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v1.1.24/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/unstable/v1.1.24/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubert@netbsd.org
HOMEPAGE=		http://www.gimp.org/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		gtk+>=1.2.7:../../x11/gtk
DEPENDS+=		mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_X11BASE=		YES
USE_XPM=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}" \
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
.else
PLIST_SRC=		${WRKDIR}/PLIST

post-build:
	@${GREP} -vx lib/gimp/.*/modules/.*\.so.* ${PKGDIR}/PLIST >${PLIST_SRC}
.endif

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gimp.m4 \
	  ${LOCALBASE}/share/aclocal/gimp.m4

.include "../../mk/bsd.pkg.mk"

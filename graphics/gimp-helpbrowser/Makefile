# $NetBSD: Makefile,v 1.1.1.1 2000/03/14 19:06:29 tron Exp $

DISTNAME=		gimp-1.1.18
PKGNAME=		${DISTNAME:S/-/-helpbrowser-/}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/unstable/v1.1.18/ \
			ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v1.1.18/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/unstable/v1.1.18/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gimp.org/

DEPENDS+=		${DISTNAME}:../gimp-current
DEPENDS+=		gnome-libs>=1.0.56:../../x11/gnome-libs

USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE} \
			--disable-perl \
			--disable-python
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" INTLLIBS="-lintl" \
			GNOME_CONFIG=${GNOME_CONFIG}

GIMPDIR=		${PKGSRCDIR}/graphics/gimp-current
FILESDIR=		${GIMPDIR}/files
PATCHDIR=		${GIMPDIR}/patches

CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
GNOME_CONFIG=		${X11BASE}/bin/gnome-config
GIMP_CONFIG=		${X11BASE}/bin/gimp-config
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == ELF)
LDFLAGS+=		-Wl,-E
.endif

SRCS=			helpbrowser.c queue.c

do-build:
.for SRC in ${SRCS}
	cd ${WRKSRC}/plug-ins/helpbrowser && \
	${CC} ${CFLAGS} `${GNOME_CONFIG} --cflags gtkxmhtml gtk glib` \
	  `${GIMP_CONFIG} --cflags` -I../.. -c ${SRC}
.endfor
	cd ${WRKSRC}/plug-ins/helpbrowser && \
	${CC} ${SRCS:S/.c/.o/} ${LDFLAGS} \
	  `${GNOME_CONFIG} --libs gtkxmhtml gtk glib` `${GIMP_CONFIG} --libs` \
	  -o helpbrowser

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plug-ins/helpbrowser/helpbrowser \
	  ${PREFIX}/lib/gimp/1.1/plug-ins

.include "../../mk/bsd.pkg.mk"

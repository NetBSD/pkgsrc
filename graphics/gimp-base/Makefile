# $NetBSD: Makefile,v 1.4 2002/09/04 14:47:36 agc Exp $

DISTNAME=		gimp-1.2.3
PKGNAME=		gimp-base-1.2.3
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.3/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

CONFLICTS+=		gimp<=1.2.3

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

# Add settings for MPEG, LIBMPEG, and GAP_DECODE_MPEG to properly support
# the MPEG library from graphics/mpeg-lib that changed it's name, as the
# configure script will default to searching from -lmpeg.
#
CONFIGURE_ENV+=		MPEG="mpeg"
CONFIGURE_ENV+=		LIBMPEG="-lmpeg_lib"
CONFIGURE_ENV+=		GAP_DECODE_MPEG="gap_decode_mpeg"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

MAKE_ENV+=		X11BASE=${X11BASE}

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

CONFIG_EXISTS!=		/bin/sh -c "type gtk-config glib-config > /dev/null"; \
			if [ $$? = 0 ]; then echo yes; else echo no; fi
.if (${CONFIG_EXISTS} == "yes") 
# make sure the installed "gimptool" doesn't refer to .buildlink
ORIG_GTK_CFLAGS!=	gtk-config --cflags
GIMPTOOL_SUBST=		-e "s|@ORIG_GTK_CFLAGS@|${ORIG_GTK_CFLAGS}|g"
ORIG_GTK_LIBS!=		gtk-config --libs
GIMPTOOL_SUBST+=	-e "s|@ORIG_GTK_LIBS@|${ORIG_GTK_LIBS}|g"
ORIG_GLIB_CFLAGS!=	glib-config --cflags
GIMPTOOL_SUBST+=	-e "s|@ORIG_GLIB_CFLAGS@|${ORIG_GLIB_CFLAGS}|g"
ORIG_GLIB_LIBS!=	glib-config --libs
GIMPTOOL_SUBST+=	-e "s|@ORIG_GLIB_LIBS@|${ORIG_GLIB_LIBS}|g"
ORIG_CFLAGS=		-I${PREFIX}/include -I${X11BASE}/include
GIMPTOOL_SUBST+=	-e "s|@ORIG_CFLAGS@|${ORIG_CFLAGS}|g"
ORIG_LDFLAGS=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib
ORIG_LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib
GIMPTOOL_SUBST+=	-e "s|@ORIG_LDFLAGS@|${ORIG_LDFLAGS}|g"
.endif

# Remove -I$(includedir) from the INCLUDES passed to the compiler as this
# defeats buildlink.
#
post-patch:
	cd ${WRKSRC};							\
	files=`${FIND} . -name "Makefile.in" -print`;			\
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED} -e "/^INCLUDES.*=.*/s|[ 	]*-I\$$(includedir)||"	\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

post-configure:
	${SED} ${GIMPTOOL_SUBST} <${WRKSRC}/gimptool-1.2 \
	 >${WRKSRC}/gimptool-1.2.tmp && \
	${MV} ${WRKSRC}/gimptool-1.2.tmp ${WRKSRC}/gimptool-1.2

pre-build:
	${LINK.c} -o ${WRKSRC}/docs/pdb_self_doc ${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/mpeg-lib/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.79 2002/02/13 19:50:05 drochner Exp $

DISTNAME=		gimp-1.2.3
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.3/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.3/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

GIMP_DATA=		gimp-data-extras-1.2.0

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	gimptool

USE_X11BASE=		yes
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

LDFLAGS+=		-Wl,--export-dynamic
MAKE_ENV+=		X11BASE=${X11BASE}

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

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

pre-build:
	${LINK.c} -o ${WRKSRC}/docs/pdb_self_doc ${FILESDIR}/pdb_self_doc.c

post-install:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV}		\
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/mpeg-lib/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

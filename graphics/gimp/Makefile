# $NetBSD: Makefile,v 1.71 2001/07/29 14:54:56 tron Exp $

DISTNAME=		gimp-1.2.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.2/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.2/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gnome-libs>=1.2.0:../../x11/gnome-libs
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		png>=1.0.11:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

GIMP_DATA=		gimp-data-extras-1.2.0

USE_X11BASE=		yes
USE_XPM=		yes
USE_GMAKE=		yes
USE_LIBINTL=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BUILD_USES_MSGFMT=	yes

EVAL_PREFIX+=		GTKDIR=gtk+
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}" \
			--disable-perl \
			--disable-python
CONFIGURE_ENV=		GNOME_CONFIG=no \
			INTLDEPS="-I${BUILDLINK_DIR}/include"

CPPFLAGS=		-I${BUILDLINK_DIR}/include
LDFLAGS+=		-L${BUILDLINK_DIR}/lib
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == ELF)
LDFLAGS+=		-Wl,-E
.endif

pre-build:
	${LINK.c} -o ${WRKSRC}/docs/pdb_self_doc ${FILESDIR}/pdb_self_doc.c

post-install:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV} \
		./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
	(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		 ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gimp.m4 \
	  ${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/mpeg-lib/buildlink.mk"

.include "../../mk/bsd.pkg.mk"

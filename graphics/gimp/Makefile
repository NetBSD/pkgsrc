# $NetBSD: Makefile,v 1.39 1999/07/06 21:52:54 tron Exp $

DISTNAME=		gimp-1.0.4
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.0/v1.0.4/ \
			ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/v1.0/v1.0.4/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.0/v1.0.4/
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=		bsieker@techfak.uni-bielefeld.de
HOMEPAGE=		http://www.gimp.org/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		gtk+-1.2.2:../../x11/gtk
DEPENDS+=		mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		tiff-3.4:../../graphics/tiff
DEPENDS+=		xpm-3.4k:../../graphics/xpm

GIMP_DATA=		gimp-data-extras-1.0.0

.ifndef DISPLAY
IS_INTERACTIVE=		yes
.endif
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}"

INFO_FILES=		pdb.info

post-configure:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV} \
		./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

pre-build:
	@if [ "$$DISPLAY" = "" ]; then \
		${ECHO} "${DISTNAME} can only be built under X11."; \
		exit 1; \
	fi
	${LINK.c} -o ${WRKSRC}/docs/pdb_self_doc ${FILESDIR}/pdb_self_doc.c

post-install:
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET})
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		 ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})

.include "../../mk/bsd.pkg.mk"

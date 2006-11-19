# $NetBSD: Makefile,v 1.11 2006/11/19 23:11:18 rillig Exp $
#

PKGNAME=		cal3d-examples-${CAL3D_VERSION}
PKGREVISION=	2

.include "../../graphics/cal3d/Makefile.common"

DISTFILES=		TheCallyDemo-0.9.1b.zip \
			cal3d-${CAL3D_VERSION}${EXTRACT_SUFX}

COMMENT=	        Tools and demos for cal3d library

USE_TOOLS+=		automake

CONFIGURE_ARGS+=	--with-cal3d=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-glut=${PREFIX:Q}
CONFIGURE_DIRS=		${WRKSRC}/examples/cally \
			${WRKSRC}/examples/miniviewer_gl \
			${WRKSRC}/tools/converter
CFLAGS+=		-DCAL3D_DATADIR='"${DATADIR}/"'
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			-lm -lGL -lX11 -lGLU -lXi -lXmu
BUILD_DIRS=		${WRKSRC}/examples/cally \
			${WRKSRC}/examples/miniviewer_gl \
			${WRKSRC}/tools/converter

DATADIR=		${PREFIX}/share/cal3d-examples/data
WRKDATADIR=		${WRKDIR}/thecallydemo-0.9.1b/data
PATCHDATA=		cally.cfg paladin.cfg skeleton.cfg

pre-configure:
	cd ${WRKSRC}/examples/cally && ./autogen.sh
	cd ${WRKSRC}/examples/miniviewer_gl && ./autogen.sh
	${CHMOD} 755 ${WRKSRC}/tools/converter/autogen.sh
	cd ${WRKSRC}/tools/converter && ./autogen.sh

SUBST_CLASSES+=		c3
SUBST_STAGE.c3=		post-configure
SUBST_FILES.c3=		${PATCHDATA:S,^,${WRKDATADIR}/,}
SUBST_SED.c3=		-e 's|@@DATADIR@@|${DATADIR}|g'

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKDATADIR} && ${PAX} -rw -pp -s ',.*\.orig$$,,' [a-z]* ${DATADIR}

.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

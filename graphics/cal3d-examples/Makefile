# $NetBSD: Makefile,v 1.21 2015/04/25 14:23:07 tnn Exp $
#

PKGNAME=		cal3d-examples-${CAL3D_VERSION}
PKGREVISION=	3

.include "../../graphics/cal3d/Makefile.common"

DISTFILES=		TheCallyDemo-0.9.1b.zip \
			cal3d-${CAL3D_VERSION}${EXTRACT_SUFX}

COMMENT=	Tools and demos for cal3d library

USE_TOOLS+=		automake pax

CONFIGURE_ARGS+=	--with-cal3d=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-glut=${BUILDLINK_PREFIX.glut:Q}
CONFIGURE_DIRS=		examples/cally \
			examples/miniviewer_gl \
			tools/converter
CFLAGS+=		-DCAL3D_DATADIR='"${DATADIR}/"'
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			-lm -lGL -lX11 -lGLU -lXi -lXmu
BUILD_DIRS=		examples/cally \
			examples/miniviewer_gl \
			tools/converter

DATADIR=		${DESTDIR}${PREFIX}/share/cal3d-examples/data
WRKDATADIR=		${WRKDIR}/TheCallyDemo-0.9.1b/data
PATCHDATA=		cally.cfg paladin.cfg skeleton.cfg

pre-configure:
	cd ${WRKSRC}/examples/cally && ./autogen.sh
	cd ${WRKSRC}/examples/miniviewer_gl && ./autogen.sh
	${CHMOD} 755 ${WRKSRC}/tools/converter/autogen.sh
	${CHMOD} 755 ${WRKSRC}/tools/converter/install-sh
	cd ${WRKSRC}/tools/converter && ./autogen.sh

SUBST_CLASSES+=		c3
SUBST_STAGE.c3=		post-configure
SUBST_FILES.c3=		${PATCHDATA:S,^,${WRKDATADIR}/,}
SUBST_SED.c3=		-e 's|@@DATADIR@@|${DATADIR}|g'

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKDATADIR} && pax -rw -pp -s ',.*\.orig$$,,' [a-z]* ${DATADIR}

.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:49 tv Exp $
#

PKGNAME=		cal3d-examples-${CAL3D_VERSION}
PKGREVISION=	1

.include "../../graphics/cal3d/Makefile.common"

DISTFILES=		TheCallyDemo-0.9.1b.zip \
			cal3d-${CAL3D_VERSION}${EXTRACT_SUFX}

COMMENT=	        Tools and demos for cal3d library

USE_X11=		YES
USE_BUILDLINK3=		yes
CONFIGURE_ARGS+=	--with-cal3d=${PREFIX}
CONFIGURE_ARGS+=	--with-glut=${PREFIX}
CONFIGURE_DIRS=		${WRKSRC}/examples/cally \
			${WRKSRC}/examples/miniviewer_gl \
			${WRKSRC}/tools/converter
CFLAGS+=		-DCAL3D_DATADIR='\"${DATADIR}/\"'
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

post-patch:
	for f in ${PATCHDATA}; do \
		${CP} ${WRKDATADIR}/$$f ${WRKDATADIR}/$$f.pkgsrc && \
		${SED} -e 's|@@DATADIR@@|${DATADIR}|g' ${WRKDATADIR}/$$f.pkgsrc > \
			${WRKDATADIR}/$$f; && \
		${RM} ${WRKDATADIR}/$$f.pkgsrc; \
		${RM} ${WRKDATADIR}/$$f.orig; \
		done

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKDATADIR} && ${PAX} -rw -pe [a-z]* ${DATADIR}

.include "../../graphics/cal3d/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

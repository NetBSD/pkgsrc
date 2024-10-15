# $NetBSD: Makefile,v 1.38 2024/10/15 16:07:00 adam Exp $

PKGNAME=	poppler-includes-${POPPLER_VERS}

COMMENT=	Poppler Xpdf includes (unsupported)

CONFLICTS+=	poppler-0.5.1{,nb*}

NO_BUILD=	yes

INCDIR=		${DESTDIR}${PREFIX}/include

CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=OFF

do-install:
	${INSTALL_DATA_DIR} ${INCDIR}
	${INSTALL_DATA_DIR} ${INCDIR}/poppler
	sed -n -f ${FILESDIR}/extract.sed ${WRKSRC}/CMakeLists.txt	\
	  | grep ^poppler/ | { while read f; do				\
	    ${INSTALL_DATA} ${WRKSRC}/"$$f" ${INCDIR}/poppler;		\
	done };
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/poppler/poppler-config.h \
		${INCDIR}/poppler
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/poppler_private_export.h \
		${INCDIR}/poppler
	for d in goo fofi splash; do					\
	    ${INSTALL_DATA_DIR} ${INCDIR}/poppler/"$$d";		\
	    sed -n -f ${FILESDIR}/extract.sed ${WRKSRC}/CMakeLists.txt	\
	      | grep "^$$d/" | { while read f; do			\
		${INSTALL_DATA} ${WRKSRC}/"$$f" ${INCDIR}/poppler/"$$d";\
	    done };							\
	done
	# do these actually belong here?
	${INSTALL_DATA} ${WRKSRC}/poppler/SignatureInfo.h ${INCDIR}/poppler
	${INSTALL_DATA} ${WRKSRC}/goo/NetPBMWriter.h ${INCDIR}/poppler/goo

.include "../../print/poppler/Makefile.common"

BUILDLINK_DEPMETHOD.fontconfig= build
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

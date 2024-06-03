# $NetBSD: Makefile,v 1.36 2024/06/03 12:22:35 jperkin Exp $

.include "../../print/poppler/Makefile.common"

PKGNAME=	poppler-includes-${POPPLER_VERS}

COMMENT=	Poppler Xpdf includes (unsupported)

CONFLICTS+=	poppler-0.5.1{,nb*}

NO_BUILD=	yes

INCDIR=	${DESTDIR}${PREFIX}/include

CMAKE_ARGS+=	-DENABLE_QT5:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_QT6:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${INCDIR}
	${INSTALL_DATA_DIR} ${INCDIR}/poppler
	sed -n -f ${FILESDIR}/extract.sed ${WRKSRC}/CMakeLists.txt	\
	  | grep ^poppler/ | { while read f; do				\
	    ${INSTALL_DATA} ${WRKSRC}/"$$f" ${INCDIR}/poppler;		\
	done };
	${INSTALL_DATA} ${WRKSRC}/poppler/poppler-config.h ${INCDIR}/poppler
	${INSTALL_DATA} ${WRKSRC}/poppler_private_export.h ${INCDIR}/poppler
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

BUILDLINK_DEPMETHOD.fontconfig= build
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

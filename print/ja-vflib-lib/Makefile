# $NetBSD: Makefile,v 1.11 2011/05/28 09:07:38 obache Exp $

.include "Makefile.common"

PKGNAME=	ja-vflib-lib-${VFLIB_VERSION}
PKGREVISION=	3

COMMENT=	Japanese Vector font library

BUILD_TARGET=		build-src
INSTALL_TARGET=		install-src

USE_TOOLS+=	pax

post-build:
.for FILE in vfontcap vfontcap.bdf
	cd ${WRKSRC};							\
	${MV} ${FILE} ${FILE}.orig;					\
	${SED} -e "s|/usr/local/share/fonts|${PREFIX}/share/fonts|g"	\
		${FILE}.orig > ${FILE};					\
	${RM} ${FILE}.orig
.endfor

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${DESTDIR}${PREFIX}/include

	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYING.LIB README.txt.JP_EUC \
		${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC} && pax -rw jTeX ${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION}
	${FIND} ${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION} -type d -print \
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${DESTDIR}${PREFIX}/share/VFlib/${VFLIB_VERSION} -type f -print \
		-exec ${CHMOD} ${SHAREMODE} {} \;

.include "../../mk/bsd.pkg.mk"

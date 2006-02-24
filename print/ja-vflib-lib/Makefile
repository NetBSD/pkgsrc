# $NetBSD: Makefile,v 1.8 2006/02/24 21:07:51 minskim Exp $

.include "Makefile.common"

PKGNAME=	ja-vflib-lib-${VFLIB_VERSION}
PKGREVISION=	2

COMMENT=	Japanese Vector font library

CONFIGURE_ARGS+=	--without-x
BUILD_TARGET=		build-src
INSTALL_TARGET=		install-src

post-build:
.for FILE in vfontcap vfontcap.bdf
	cd ${WRKSRC};							\
	${MV} ${FILE} ${FILE}.orig;					\
	${SED} -e "s|/usr/local/share/fonts|${PREFIX}/share/fonts|g"	\
		${FILE}.orig > ${FILE};					\
	${RM} ${FILE}.orig
.endfor

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

	${INSTALL_DATA_DIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC} && ${PAX} -rw jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION}
	${FIND} ${PREFIX}/share/VFlib/${VFLIB_VERSION} -type d -print \
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${PREFIX}/share/VFlib/${VFLIB_VERSION} -type f -print \
		-exec ${CHMOD} ${SHAREMODE} {} \;

.include "../../mk/bsd.pkg.mk"

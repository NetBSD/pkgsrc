# $NetBSD: Makefile,v 1.3 2001/02/16 15:25:32 wiz Exp $

PKGNAME=		ja-vflib-lib-${VFLIB_VERSION}

COMMENT=		Japanese Vector font library

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		build-src
INSTALL_TARGET=		install-src

post-build:
.for FILE in vfontcap vfontcap.bdf
	cd ${WRKSRC}; \
	${MV} ${FILE} ${FILE}.orig; \
	${SED} -e "s,/usr/local/share/fonts,${PREFIX}/share/fonts,g" \
		< ${FILE}.orig > ${FILE}; \
	${RM} ${FILE}.orig
.endfor

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

	${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION}
	cd ${WRKSRC}; ${PAX} -rw jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION}
	${CHMOD} -R a-w ${PREFIX}/share/VFlib/${VFLIB_VERSION}

.include "../../japanese/vflib-lib/Makefile.common"

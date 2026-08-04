# $NetBSD: Makefile,v 1.13 2026/08/04 20:29:13 wiz Exp $

.include "Makefile.common"

PKGNAME=	ja-vflib-lib-${VFLIB_VERSION}
PKGREVISION=	3

COMMENT=	Japanese Vector font library

BUILD_TARGET=		build-src
INSTALL_TARGET=		install-src

USE_TOOLS+=	pax

post-build:
.for file in vfontcap vfontcap.bdf
	cd ${WRKSRC};							\
	${MV} ${file} ${file}.orig;					\
	${SED} -e "s|/usr/local/share/fonts|${PREFIX}/share/fonts|g"	\
		${file}.orig > ${file};					\
	${RM} ${file}.orig
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"

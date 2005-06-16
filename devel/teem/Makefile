# $NetBSD: Makefile,v 1.6 2005/06/16 02:41:21 jlam Exp $
#

DISTNAME=		teem-1.8.0-src
PKGNAME=		${DISTNAME:C/-src//}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teem/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://teem.sourceforge.net/
COMMENT=		Libraries for manipulation of Structured Scientific Data

USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386"
NARCH=32
LARCH=32
.  elif ${MACHINE_ARCH} == "x86_64"
NARCH=64
LARCH=amd64
.  endif

TEEM_ARCH=netbsd.${NARCH}

do-configure:
	cd ${WRKSRC} && ${CP} -pR linux.${LARCH} ${TEEM_ARCH}

.elif ${OPSYS} == "Linux" && ${MACHINE_ARCH} == "i386"
TEEM_ARCH=linux.32
.else
PKG_FAIL_REASON="Support for this platform has not yet been added."
.endif

MAKE_ENV+=	TEEM_ARCH=${TEEM_ARCH}					\
		TEEM_PNG=1 TEEM_BZIP2=1 TEEM_ZLIB=1 TEEM_PTHREAD=1	\
		TEEM_PNG_IPATH="-I${BUILDLINK_PREFIX.png}/include"	\
		TEEM_PNG_LPATH="-L${BUILDLINK_PREFIX.png}/lib"		\
		TEEM_BZIP2_IPATH="-I${BUILDLINK_PREFIX.bzip2}/include"	\
		TEEM_BZIP2_LPATH="-L${BUILDLINK_PREFIX.bzip2}/lib"	\
		TEEM_ZLIB_IPATH="-I${BUILDLINK_PREFIX.zlib}/include"	\
		TEEM_ZLIB_LPATH="-L${BUILDLINK_PREFIX.zlib}/lib"	\
		TEEM_PTHREAD_IPATH="-I${BUILDLINK_PREFIX.pthread}/include" \
		TEEM_PTHREAD_LPATH="-L${BUILDLINK_PREFIX.pthread}/lib"

do-build:
	cd ${WRKSRC}/src && ${MAKE_ENV} ${GMAKE}

pre-install:
	${RM} -f ${WRKSRC}/${TEEM_ARCH}/bin/.empty		\
		${WRKSRC}/${TEEM_ARCH}/lib/.empty

do-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${PREFIX}/include/
	cd ${WRKSRC}/${TEEM_ARCH}/bin && ${PAX} -rw . ${PREFIX}/bin/
	cd ${WRKSRC}/${TEEM_ARCH}/lib && ${PAX} -rw . ${PREFIX}/lib/

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.18 2012/05/23 03:35:27 dholland Exp $
#

DISTNAME=		teem-1.8.0-src
PKGNAME=		${DISTNAME:C/-src//}
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teem/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://teem.sourceforge.net/
COMMENT=		Libraries for manipulation of Structured Scientific Data

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pax

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
.  if ${MACHINE_ARCH} == "i386"
NARCH=32
LARCH=32
.  elif ${MACHINE_ARCH} == "x86_64"
NARCH=64
LARCH=amd64
.  else
PKG_FAIL_REASON+=	"Need configuration rules for ${MACHINE_ARCH}."
.  endif

TEEM_ARCH=netbsd.${NARCH}

do-configure:
	cd ${WRKSRC} && ${CP} -pR linux.${LARCH} ${TEEM_ARCH}

.elif ${OPSYS} == "Linux" && ${MACHINE_ARCH} == "i386"
TEEM_ARCH=linux.32
.else
PKG_FAIL_REASON+=	"Support for this platform has not yet been added."
.endif

MAKE_ENV+=	TEEM_ARCH=${TEEM_ARCH:Q}					\
		TEEM_PNG=1 TEEM_BZIP2=1 TEEM_ZLIB=1 TEEM_PTHREAD=1	\
		TEEM_PNG_IPATH="-I${BUILDLINK_PREFIX.png}/include"	\
		TEEM_PNG_LPATH="-L${BUILDLINK_PREFIX.png}/lib"		\
		TEEM_BZIP2_IPATH="-I${BUILDLINK_PREFIX.bzip2}/include"	\
		TEEM_BZIP2_LPATH="-L${BUILDLINK_PREFIX.bzip2}/lib"	\
		TEEM_ZLIB_IPATH="-I${BUILDLINK_PREFIX.zlib}/include"	\
		TEEM_ZLIB_LPATH="-L${BUILDLINK_PREFIX.zlib}/lib"	\
		TEEM_PTHREAD_IPATH="-I${BUILDLINK_PREFIX.pthread}/include" \
		TEEM_PTHREAD_LPATH="-L${BUILDLINK_PREFIX.pthread}/lib"

INSTALLATION_DIRS=	bin include lib

do-build:
	cd ${WRKSRC}/src && ${MAKE_ENV} ${GMAKE}

pre-install:
	${RM} -f ${WRKSRC}/${TEEM_ARCH}/bin/.empty		\
		${WRKSRC}/${TEEM_ARCH}/lib/.empty

do-install:
	cd ${WRKSRC}/include && pax -rw . ${DESTDIR}${PREFIX}/include/
	cd ${WRKSRC}/${TEEM_ARCH}/bin && pax -rw . ${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC}/${TEEM_ARCH}/lib && pax -rw . ${DESTDIR}${PREFIX}/lib/

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

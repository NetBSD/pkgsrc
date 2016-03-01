# $NetBSD: Makefile,v 1.34 2016/03/01 20:16:33 joerg Exp $
#

DISTNAME=	perfuse-20120206
CATEGORIES=	filesystems
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/perfuse/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	PUFFS Enabled Relay to FUSE
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/src/
BUILD_DIRS=	lib/libperfuse usr.sbin/perfused
BUILDLINK_TRANSFORM=	rm:-Werror
CPPFLAGS+=	-DPERFUSE_DEBUG -D_PATH_PERFUSED=\"${PREFIX}/sbin/perfused\"
CPPFLAGS.NetBSD+=	-D_KERNTYPES

CFLAGS+=	-g

INSTALLATION_DIRS=	include lib sbin

pre-build:
	${LN} -s ${WRKSRC}/lib/libperfuse/perfuse.h ${BUILDLINK_DIR}/include/
	${LN} -s ${WRKSRC}/lib/libperfuse/libperfuse.so ${BUILDLINK_DIR}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libperfuse/perfuse.h \
	    ${DESTDIR}/${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/lib/libperfuse/libperfuse.so \
	    ${DESTDIR}/${PREFIX}/lib/
	cd ${DESTDIR}${PREFIX}/lib && \
		ln -s libperfuse.so libperfuse.so.0 && \
		ln -s libperfuse.so libperfuse.so.0.0

	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/perfused/perfused \
	    ${DESTDIR}/${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

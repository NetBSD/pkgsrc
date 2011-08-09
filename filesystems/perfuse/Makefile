# $NetBSD: Makefile,v 1.23 2011/08/09 07:22:52 manu Exp $
#

DISTNAME=	perfuse-20110809
CATEGORIES=	filesystems
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/perfuse/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	PUFFS Enabled Relay to FUSE
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/src/
BUILD_DIRS=	lib/libperfuse usr.sbin/perfused
BUILDLINK_TRANSFORM=	rm:-Werror
CFLAGS+=	-D_PATH_PERFUSED=\"${PREFIX}/sbin/perfused\"
CFLAGS+=	-DPERFUSE_DEBUG -g

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

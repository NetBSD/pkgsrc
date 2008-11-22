# $NetBSD: Makefile,v 1.1.1.1 2008/11/22 13:48:23 jmcneill Exp $
#

DISTNAME=		libvolume_id-0.81.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.marcuscom.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library to provide file system type information

USE_TOOLS+=		gmake pkg-config ranlib

MAKE_ENV+=		E=@${ECHO}
MAKE_ENV+=		RANLIB=ranlib
MAKE_ENV+=		AR=ar
MAKE_ENV+=		Q=@
MAKE_ENV+=		prefix=${PREFIX}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${PREFIX}/lib/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${PREFIX}/lib/libvolume_id.a
	${INSTALL_LIB} ${WRKSRC}/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so

.include "../../mk/bsd.pkg.mk"

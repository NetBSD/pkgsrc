# $NetBSD: Makefile,v 1.2 2008/11/26 07:47:56 hasso Exp $
#

DISTNAME=		libvolume_id-0.81.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.marcuscom.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library to provide file system type information

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	include lib lib/pkgconfig 
USE_TOOLS+=		gmake pkg-config ranlib

MAKE_ENV+=		E=@${ECHO}
MAKE_ENV+=		RANLIB=ranlib
MAKE_ENV+=		AR=ar
MAKE_ENV+=		Q=@
MAKE_ENV+=		prefix=${PREFIX}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${DESTDIR}${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${DESTDIR}${PREFIX}/lib/libvolume_id.a
	${INSTALL_LIB} ${WRKSRC}/libvolume_id.so.0 ${DESTDIR}${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${DESTDIR}${PREFIX}/lib/libvolume_id.so

.include "../../mk/bsd.pkg.mk"

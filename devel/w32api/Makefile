# $NetBSD: Makefile,v 1.22 2005/12/05 20:50:09 rillig Exp $

DISTNAME=	w32api-2.5-src
PKGNAME=	w32api-2.5
#PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mingw/}
DISTFILES+=	${DISTNAME}.tar.gz pe-crt-1.2.1.tar.gz
SITES_pe-crt-1.2.1.tar.gz=http://www.hauN.org/kent/

MAINTAINER=	peace-sacrifice@hauN.org
HOMEPAGE=	http://www.mingw.org/
COMMENT=	Free headers and libraries for the Win32 API

BUILD_DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PE_CC=		${CROSSBASE}/bin/i386-netbsdpe-cc -I${WRKSRC}/include
PE_AR=		${CROSSBASE}/bin/i386-netbsdpe-ar
CRTWRKSRC=	${WRKDIR}/pe-crt-1.2.1
PE_CPPFLAGS+=	-I${WRKSRC}/include
MAKE_FLAGS+=	PE_CPPFLAGS=${PE_CPPFLAGS:Q}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

# Building no import libraries but two static libraries.
do-build:
	cd ${WRKSRC}/lib \
		&& ${PE_CC} -c -o dxguid.o dxguid.c \
		&& ${PE_CC} -c -o uuid.o uuid.c \
		&& ${PE_AR} r libdxguid.a dxguid.o \
		&& ${PE_AR} r libuuid.a uuid.o
	${_PKG_SILENT}cd ${CRTWRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/*.h ${CROSSBASE}/i386-netbsdpe/include/GL
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include/ddk
	${INSTALL_DATA} ${WRKSRC}/include/ddk/*.h ${CROSSBASE}/i386-netbsdpe/include/ddk
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/lib
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${CROSSBASE}/i386-netbsdpe/lib
	${_PKG_SILENT}cd ${CRTWRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"

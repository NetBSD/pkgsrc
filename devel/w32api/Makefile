# $NetBSD: Makefile,v 1.18 2003/09/21 19:58:38 kent Exp $

DISTNAME=	w32api-2.4-src
PKGNAME=	w32api-2.4
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mingw/}
DISTFILES+=	${DISTNAME}.tar.gz pe-crt-1.2.1.tar.gz
SITES_pe-crt-1.2.1.tar.gz=http://www.hauN.org/kent/

MAINTAINER=	peace-sacrifice@hauN.org
HOMEPAGE=	http://www.mingw.org/
COMMENT=	Free headers and libraries for the Win32 API

BUILD_DEPENDS+=	cross-i386-netbsdpe>=1.3:../../cross/i386-netbsdpe

PE_CC=		${CROSSBASE}/bin/i386-netbsdpe-cc -I${WRKSRC}/include
PE_AR=		${CROSSBASE}/bin/i386-netbsdpe-ar
CRTWRKSRC=	${WRKDIR}/pe-crt-1.2.1
PE_CPPFLAGS+=	-I${WRKDIR}/include
MAKE_FLAGS+=	PE_CPPFLAGS="${PE_CPPFLAGS}"
FIXPATTERN=	s/(CALLBACK/ CALLBACK (/g; s/typedef \(.*\)(NTAPI/typedef \1 NTAPI (/g; s/typedef \(.*\)(WINAPI/typedef \1 WINAPI (/g; s/typedef \(.*\)(STDAPICALLTYPE/typedef \1 STDAPICALLTYPE (/g; s/typedef \(.*\)(APIENTRY/typedef \1 APIENTRY (/g; s/typedef \(.*\)(PASCAL/typedef \1 PASCAL (/g; s/typedef \(.*\)(STDCALL/typedef \1 STDCALL (/g; s/typedef \(.*\)(__RPC_API/typedef \1 __RPC_API (/g; s/typedef \(.*\)(__RPC_USER/typedef \1 __RPC_USER (/g; s/typedef \(.*\)(__stdcall/typedef \1 __stdcall (/g; s/typedef \(.*\)(__RPC_STUB/typedef \1 __RPC_STUB (/g

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
	${MKDIR} ${WRKDIR}/include
	${MKDIR} ${WRKDIR}/include/GL
	${MKDIR} ${WRKDIR}/include/ddk
	for i in ${WRKSRC}/include/*.h; do \
		${SED} "${FIXPATTERN}" $$i > ${WRKDIR}/include/`basename $$i`; \
	done
	for i in ${WRKSRC}/include/GL/*.h; do \
		${SED} "${FIXPATTERN}" $$i > ${WRKDIR}/include/GL/`basename $$i`; \
	done
	for i in ${WRKSRC}/include/ddk/*.h; do \
		${SED} "${FIXPATTERN}" $$i > ${WRKDIR}/include/ddk/`basename $$i`; \
	done
	${_PKG_SILENT}cd ${CRTWRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA} ${WRKDIR}/include/*.h ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include/GL
	${INSTALL_DATA} ${WRKDIR}/include/GL/*.h ${CROSSBASE}/i386-netbsdpe/include/GL
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include/ddk
	${INSTALL_DATA} ${WRKDIR}/include/ddk/*.h ${CROSSBASE}/i386-netbsdpe/include/ddk
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/lib
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${CROSSBASE}/i386-netbsdpe/lib
	${_PKG_SILENT}cd ${CRTWRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2002/03/18 03:25:46 kent Exp $
# $PEACE: Makefile,v 1.18 2001/12/16 16:23:38 kent Exp $

DISTNAME=	w32api-1.2-src
PKGNAME=	w32api-1.2
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	http://prdownloads.sourceforge.net/mingw/

MAINTAINER=	peace-sacrifice@hauN.org
HOMEPAGE=	http://www.mingw.org/
COMMENT=	Free headers and libraries for the Win32 API

BUILD_DEPENDS+=	cross-i386-netbsdpe:../../cross/i386-netbsdpe

PE_CC=		${CROSSBASE}/bin/i386-netbsdpe-cc -I${WRKSRC}/include
PE_AR=		${CROSSBASE}/bin/i386-netbsdpe-ar

# Building no import libraries but two static libraries.
do-build:
	cd ${WRKSRC}/lib \
		&& ${PE_CC} -c -o dxguid.o dxguid.c \
		&& ${PE_CC} -c -o uuid.o uuid.c \
		&& ${PE_AR} r libdxguid.a dxguid.o \
		&& ${PE_AR} r libuuid.a uuid.o
	${MKDIR} ${WRKDIR}/include
	for i in ${WRKSRC}/include/*.h; do \
		${SED} 's/(CALLBACK/ CALLBACK (/g; s/typedef \(.*\)(NTAPI/typedef \1 NTAPI (/g; s/typedef \(.*\)(WINAPI/typedef \1 WINAPI (/g; s/typedef \(.*\)(STDAPICALLTYPE/typedef \1 STDAPICALLTYPE (/g; s/typedef \(.*\)(APIENTRY/typedef \1 APIENTRY (/g; s/typedef \(.*\)(PASCAL/typedef \1 PASCAL (/g; s/typedef \(.*\)(STDCALL/typedef \1 STDCALL (/g; s/typedef \(.*\)(__RPC_API/typedef \1 __RPC_API (/g; s/typedef \(.*\)(__RPC_USER/typedef \1 __RPC_USER (/g; s/typedef \(.*\)(__stdcall/typedef \1 __stdcall (/g; s/typedef \(.*\)(__RPC_STUB/typedef \1 __RPC_STUB (/g' $$i > ${WRKDIR}/include/`basename $$i`; \
	done

do-install:
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA} ${WRKDIR}/include/*.h ${CROSSBASE}/i386-netbsdpe/include
	${INSTALL_DATA_DIR} ${CROSSBASE}/i386-netbsdpe/lib
	${INSTALL_DATA} ${WRKSRC}/lib/lib*.a ${CROSSBASE}/i386-netbsdpe/lib

.include "../../mk/bsd.pkg.mk"

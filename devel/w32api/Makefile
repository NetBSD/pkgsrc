# $NetBSD: Makefile,v 1.8 2001/11/29 01:12:30 hubertf Exp $
# $PEACE: Makefile,v 1.15 2001/10/20 03:00:07 kent Exp $

DISTNAME=		w32api-1.1-src
PKGNAME=		w32api-1.1
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=		devel
MASTER_SITES=		http://prdownloads.sourceforge.net/mingw/

MAINTAINER=		peace-sacrifice@hauN.org
HOMEPAGE=		http://www.mingw.org/
COMMENT=		Free headers and libraries for the Win32 API

BUILD_DEPENDS+=		cross-i386-netbsdpe:../../cross/i386-netbsdpe

PE_CC=			${CROSSBASE}/bin/i386-netbsdpe-cc -I${WRKSRC}/include
PE_AR=			${CROSSBASE}/bin/i386-netbsdpe-ar
#HAS_CONFIGURE=		yes
#CONFIGURE_ARGS+=	"--prefix=${PREFIX}/cross/i386-netbsdpe"
#CONFIGURE_ENV+=		CC="${PREFIX}/cross/i386-netbsdpe/bin/gcc -I/usr/include"
#CONFIGURE_ENV+=		AS="${PREFIX}/cross/i386-netbsdpe/bin/as"
#CONFIGURE_ENV+=		DLLTOOL="${PREFIX}/cross/i386-netbsdpe/bin/dlltool"

#USE_GMAKE=		yes

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

# $NetBSD: Makefile,v 1.2 2002/09/01 15:13:52 kent Exp $
#
PEACE_VERSION=	20020901
DISTNAME=	peace-0.0.${PEACE_VERSION}
SITES_peace-20020901.tar.gz=http://cvs.kshosen.ac.jp/src/
CATEGORIES=	emulators

MAINTAINER=	peace-sacrifice@hauN.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Enable to run Win32 executables

ICU_VER=	1.8.1
ICU_SHORT_VER=	18
DISTFILES+=	freetype-dll-2.0.1nb1.tgz \
		icu-dll-${ICU_VER}nb3.tgz \
		icu-data-${ICU_VER}nb1.tgz \
		peace-i386-sysdll-20020715.tgz \
		peace-i386-implib-20020124.tar.gz \
		i386-netbsdpe-stl-3.3.tgz \
		peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
# bin/showstack requires perl5
# DEPENDS+=	perl5:../../lang/perl5
ONLY_FOR_PLATFORMS=	NetBSD-1.5ZC-i386 NetBSD-1.6*-i386

BUILD_DEPENDS=	cross-i386-netbsdpe>=1.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	w32api>=1.5nb1:../../devel/w32api
WRKSRC=		${WRKDIR}/peace
CFLAGS+=	-I${WRKDIR}/cross/i386-netbsdpe/include \
		-I${WRKDIR}/cross/i386-netbsdpe/include/c++
LDFLAGS=	-L. -L${WRKSRC}/lib
PECOFFDIR=	${PREFIX}/emul/pecoff
MAKE_FLAGS+=	PECOFFDIR=${PECOFFDIR} \
		CROSSBASE=${CROSSBASE} \
		CHECK_DEPENDENTS=NO
MAKE_COMMAND=	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-configure:
# import libraries in peace-i386-implib
	${CP} ${WRKDIR}/lib/*.a ${WRKSRC}/lib
# import libraries in icu and freetype
	${CP} ${WRKDIR}/cross/i386-netbsdpe/lib/*.a ${WRKSRC}/lib
# static libc
	${CP} ${WRKDIR}/linklib/NetBSD-libc/obj/libc.a ${WRKSRC}/linklib/NetBSD-libc/

do-build:
	${_PKG_SILENT}cd ${WRKSRC}/libexec/ld.pe_so && ${MAKE_COMMAND}
	${_PKG_SILENT}cd ${WRKSRC}/dll && ${MAKE_COMMAND}
	${_PKG_SILENT}cd ${WRKSRC}/bin && ${MAKE_COMMAND}

do-install:
	${INSTALL_PROGRAM_DIR} ${PECOFFDIR}/usr/libexec
	cd ${WRKSRC}/libexec/ld.pe_so && ${MAKE_COMMAND} install
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/lib
	${_PKG_SILENT}cd ${WRKSRC}/dll && ${MAKE_COMMAND} install
	${_PKG_SILENT}cd ${WRKSRC}/bin && ${MAKE_COMMAND} install
	${INSTALL_DATA} ${WRKDIR}/lib/*.dll ${WRKDIR}/*.dll ${PECOFFDIR}/usr/lib
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/pkg/etc/icudll
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/pkg/share/icudll/${ICU_VER}
	${INSTALL_DATA} ${WRKDIR}/etc/icudll/convrtrs.txt ${PECOFFDIR}/usr/pkg/etc/icudll
	${INSTALL_DATA} ${WRKDIR}/share/icudll/${ICU_VER}/icudt${ICU_SHORT_VER}l.dat \
		${PECOFFDIR}/usr/pkg/share/icudll/${ICU_VER}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2010/02/11 15:16:18 joerg Exp $

PKGNAME=		sapnwrfcsdk-7.11
CATEGORIES=		devel

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../emulators/sap/Makefile.common"

DISTRIBUTED_SHEXT=	so
.if ${SAP_OPSYS} == "linux"
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		NWRFC_1-20004549
.elif ${SAP_ARCH} == "i386"
DISTNAME=		NWRFC_1-20004547
.elif ${SAP_ARCH} == "powerpc"
DISTNAME=		NWRFC_1-20004546
.elif ${SAP_ARCH} == "ia64"
DISTNAME=		NWRFC_1-20004548
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "aix"
.if ${SAP_ARCH} == "powerpc"
DISTNAME=		NWRFC_1-20004303
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "hpux"
PLIST_VARS+=		ia64 hppa
.if ${SAP_ARCH} == "ia64"
DISTNAME=		NWRFC_1-20004304
PLIST.ia64=		yes
.elif ${SAP_ARCH} == "hppa"
DISTNAME=		NWRFC_1-20004545
DISTRIBUTED_SHEXT=	sl
PLIST.parisc=		yes
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "solaris"
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		NWRFC_1-20004556
.elif ${SAP_ARCH} == "sparc64"
DISTNAME=		NWRFC_1-20004557
.else
BROKEN=		Architecture ${MACHINE_ARCH} on this platform not supported
.endif
.elif ${SAP_OPSYS} == "interix"
DISTRIBUTED_SHEXT=	dll
.if ${SAP_ARCH} == "x86_64"
DISTNAME=		NWRFC_1-20004552
.elif ${SAP_ARCH} == "i586"
DISTNAME=		NWRFC_1-20004550
.elif ${SAP_ARCH} == "ia64"
DISTNAME=		NWRFC_1-20004551
.else
BROKEN=		Architecture ${MACHINE_ARCH} on platform ${OPSYS} not supported
.endif
.else
BROKEN=		Platform ${OPSYS} not supported
.endif

.if !exists(DOWNLOADED_DISTFILE) && make(pbulk-index)
PKG_FAIL_REASON+=	"Missing distfile"
.endif

EXTRACT_CMD=		SAPCAR -xvf ${DOWNLOADED_DISTFILE}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		SAP NetWeaver RFC SDK
LICENSE=		sap-license

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}/nwrfcsdk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rfcexec ${DESTDIR}${PREFIX}/bin/rfcexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/startrfc ${DESTDIR}${PREFIX}/bin/startrfc
	${INSTALL_DATA} ${WRKSRC}/include/sapdecf.h ${DESTDIR}${PREFIX}/include/sapdecf.h
	${INSTALL_DATA} ${WRKSRC}/include/sapnwrfc.h ${DESTDIR}${PREFIX}/include/sapnwrfc.h
	${INSTALL_DATA} ${WRKSRC}/include/sapuc.h ${DESTDIR}${PREFIX}/include/sapuc.h
	${INSTALL_DATA} ${WRKSRC}/include/sapucx.h ${DESTDIR}${PREFIX}/include/sapucx.h
	${INSTALL_LIB} ${WRKSRC}/lib/libicudecnumber.${DISTRIBUTED_SHEXT} ${DESTDIR}${PREFIX}/lib/libicudecnumber.${DISTRIBUTED_SHEXT}
.if ${SAP_OPSYS} != "interix"
	${INSTALL_LIB} ${WRKSRC}/lib/libsapnwrfc.${DISTRIBUTED_SHEXT} ${DESTDIR}${PREFIX}/lib/libsapnwrfc.${DISTRIBUTED_SHEXT}
.endif
	${INSTALL_LIB} ${WRKSRC}/lib/libsapucum.${DISTRIBUTED_SHEXT} ${DESTDIR}${PREFIX}/lib/libsapucum.${DISTRIBUTED_SHEXT}
.if ${SAP_OPSYS} == "linux" || ${SAP_OPSYS} == "solaris"
	${INSTALL_LIB} ${WRKSRC}/lib/libicudata.so.34 ${DESTDIR}${PREFIX}/lib/libicudata.so.34
	${INSTALL_LIB} ${WRKSRC}/lib/libicui18n.so.34 ${DESTDIR}${PREFIX}/lib/libicui18n.so.34
	${INSTALL_LIB} ${WRKSRC}/lib/libicuuc.so.34 ${DESTDIR}${PREFIX}/lib/libicuuc.so.34
	${LN} -s libicudata.so.34 ${DESTDIR}${PREFIX}/lib/libicudata.so
	${LN} -s libicui18n.so.34 ${DESTDIR}${PREFIX}/lib/libicui18n.so
	${LN} -s libicuuc.so.34 ${DESTDIR}${PREFIX}/lib/libicuuc.so
.elif ${SAP_OPSYS} == "aix"
	${INSTALL_LIB} ${WRKSRC}/lib/libicudata34.a ${DESTDIR}${PREFIX}/lib/libicudata34.a
	${INSTALL_LIB} ${WRKSRC}/lib/libicui18n34.a ${DESTDIR}${PREFIX}/lib/libicui18n34.a
	${INSTALL_LIB} ${WRKSRC}/lib/libicuuc34.a ${DESTDIR}${PREFIX}/lib/libicuuc34.a
	${LN} -s libicudata34.a ${DESTDIR}${PREFIX}/lib/libicudata.a
	${LN} -s libicui18n34.a ${DESTDIR}${PREFIX}/lib/libicui18n.a
	${LN} -s libicuuc34.a ${DESTDIR}${PREFIX}/lib/libicuuc.a
.elif ${SAP_OPSYS} == "hpux"
	${INSTALL_LIB} ${WRKSRC}/lib/libicudata.sl.34 ${DESTDIR}${PREFIX}/lib/libicudata.sl.34
	${INSTALL_LIB} ${WRKSRC}/lib/libicui18n.sl.34 ${DESTDIR}${PREFIX}/lib/libicui18n.sl.34
	${INSTALL_LIB} ${WRKSRC}/lib/libicuuc.sl.34 ${DESTDIR}${PREFIX}/lib/libicuuc.sl.34
	${LN} -s libicudata.sl.34 ${DESTDIR}${PREFIX}/lib/libicudata.sl
	${LN} -s libicui18n.sl.34 ${DESTDIR}${PREFIX}/lib/libicui18n.sl
	${LN} -s libicuuc.sl.34 ${DESTDIR}${PREFIX}/lib/libicuuc.sl
.elif ${SAP_OPSYS} == "interix"
	${INSTALL_LIB} ${WRKSRC}/lib/icudt34.dll ${DESTDIR}${PREFIX}/lib/icudt34.dll
	${INSTALL_LIB} ${WRKSRC}/lib/icuin34.dll ${DESTDIR}${PREFIX}/lib/icuin34.dll
	${INSTALL_LIB} ${WRKSRC}/lib/icuuc34.dll ${DESTDIR}${PREFIX}/lib/icuuc34.dll
	${INSTALL_LIB} ${WRKSRC}/lib/sapdecfICUlib.lib ${DESTDIR}${PREFIX}/lib/sapdecfICUlib.lib
	${INSTALL_LIB} ${WRKSRC}/lib/sapnwrfc.dll ${DESTDIR}${PREFIX}/lib/sapnwrfc.dll
	${INSTALL_LIB} ${WRKSRC}/lib/sapnwrfc.lib ${DESTDIR}${PREFIX}/lib/sapnwrfc.lib
	${INSTALL_LIB} ${WRKSRC}/lib/libsapucum.lib ${DESTDIR}${PREFIX}/lib/libsapucum.lib
.endif
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk
	${INSTALL_DATA} ${WRKSRC}/demo/companyClient.c ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/companyClient.c
	${INSTALL_DATA} ${WRKSRC}/demo/rfcexec.cpp ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/rfcexec.cpp
	${INSTALL_DATA} ${WRKSRC}/demo/rfcexec.h ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/rfcexec.h
	${INSTALL_DATA} ${WRKSRC}/demo/sapnwrfc.ini ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/sapnwrfc.ini
	${INSTALL_DATA} ${WRKSRC}/demo/sflightClient.c ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/sflightClient.c
	${INSTALL_DATA} ${WRKSRC}/demo/startrfc.cpp ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/startrfc.cpp
	${INSTALL_DATA} ${WRKSRC}/demo/startrfc.h ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/startrfc.h
	${INSTALL_DATA} ${WRKSRC}/demo/stfcDeepTableServer.c ${DESTDIR}${PREFIX}/share/examples/sapnwrfcsdk/stfcDeepTableServer.c

.include "../../mk/bsd.pkg.mk"

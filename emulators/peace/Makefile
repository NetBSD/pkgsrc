# $NetBSD: Makefile,v 1.8 2003/09/25 09:19:28 dmcmahill Exp $
#
PEACE_VERSION=	20030919
DISTNAME=	peace-0.0.${PEACE_VERSION}
SITES_peace-20030919.tar.gz=http://cvs.kshosen.ac.jp/PEACE/src/
WRKSRC=		${WRKDIR}/peace
CATEGORIES=	emulators

MAINTAINER=	peace-sacrifice@hauN.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Enable to run Win32 executables

DISTFILES+=	i386-netbsdpe-stl-3.3.tgz \
		peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
ONLY_FOR_PLATFORM=      NetBSD-1.6[Q-Z]*-* NetBSD-[2-9]*-*
# bin/showstack requires perl5
# DEPENDS+=	perl5:../../lang/perl5
DEPENDS+=	icu>=2.4nb1:../../textproc/icu

BUILD_DEPENDS=	cross-i386-netbsdpe>=1.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	w32api>=2.4:../../devel/w32api
BUILD_DEPENDS+= x11-links-*:../../pkgtools/x11-links
CPPFLAGS+=	-I${WRKDIR}/cross/i386-netbsdpe/include \
		-I${WRKDIR}/cross/i386-netbsdpe/include/c++
LDFLAGS=	-L${WRKSRC}/lib
PECOFFDIR=	${PREFIX}/emul/pecoff
MAKE_FLAGS+=	PECOFFDIR=${PECOFFDIR} \
		LOCALBASE=${LOCALBASE} \
		CROSSBASE=${CROSSBASE} \
		X11BASE=${X11BASE} \
		CHECK_DEPENDENTS=NO
MAKE_COMMAND=	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${PECOFFDIR}/usr/libexec
	cd ${WRKSRC}/libexec/ld.pe_so && ${MAKE_COMMAND} install
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/lib
	${_PKG_SILENT}cd ${WRKSRC}/dll && ${MAKE_COMMAND} install
	${_PKG_SILENT}cd ${WRKSRC}/bin && ${MAKE_COMMAND} install

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2005/06/09 14:25:49 kent Exp $
#
PEACE_VERSION=	0.0.20050609
DISTNAME=	peace-${PEACE_VERSION}
SITES_peace-0.0.20050609.tar.gz=http://chiharu.hauN.org/peace/dist/
CATEGORIES=	emulators

MAINTAINER=	kent@NetBSD.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Enable to run Win32 executables

DISTFILES+=	peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
ONLY_FOR_PLATFORM=      NetBSD-1.6Z[D-Z]*-* NetBSD-[2-9]*-*
DEPENDS+=	icu>=2.4nb1:../../textproc/icu
# bin/showstack requires perl5 and cross-i386-netbsdpe
# DEPENDS+=	perl5:../../lang/perl5
# DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe

BUILD_DEPENDS=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	w32api>=2.5:../../devel/w32api
BUILD_DEPENDS+= x11-links-*:../../pkgtools/x11-links

CPPFLAGS+=	-I${WRKDIR}/cross/i386-netbsdpe/include
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

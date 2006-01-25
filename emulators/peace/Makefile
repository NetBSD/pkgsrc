# $NetBSD: Makefile,v 1.17 2006/01/25 08:32:51 kent Exp $
#
PEACE_VERSION=	0.0.20060125
DISTNAME=	peace-${PEACE_VERSION}
SITES_peace-0.0.20060125.tar.gz=http://chiharu.hauN.org/peace/dist/
CATEGORIES=	emulators

MAINTAINER=	kent@NetBSD.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Enable to run Win32 executables

BROKEN_IN=	pkgsrc-2005Q4

DISTFILES+=	peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
ONLY_FOR_PLATFORM=      NetBSD-[2-9]*-i386
DEPENDS+=	icu>=2.4nb1:../../textproc/icu
# bin/showstack requires perl5 and cross-i386-netbsdpe
# DEPENDS+=	perl5:../../lang/perl5
# DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe

BUILD_DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	w32api>=2.5:../../devel/w32api
BUILD_DEPENDS+= x11-links-*:../../pkgtools/x11-links

LDFLAGS+=	-L${WRKSRC}/lib
PECOFFDIR=	${PREFIX}/emul/pecoff
MAKE_FLAGS+=	PECOFFDIR=${PECOFFDIR:Q} \
		LOCALBASE=${LOCALBASE:Q} \
		CROSSBASE=${CROSSBASE:Q} \
		X11BASE=${X11BASE:Q} \
		CHECK_DEPENDENTS=NO
MAKE_COMMAND=	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${PECOFFDIR}/usr/libexec
	cd ${WRKSRC}/libexec/ld.pe_so && ${MAKE_COMMAND} install
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/lib
	${_PKG_SILENT}cd ${WRKSRC}/dll && ${MAKE_COMMAND} install
	${_PKG_SILENT}cd ${WRKSRC}/bin && ${MAKE_COMMAND} install

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 12:17:26 rh Exp $
#

DISTNAME=		${PKGNAME}-beta-lin
PKGNAME=		eagle-3.92r0
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cadsoft.de/pub/betatest/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.cadsoft.de/

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

ONLY_FOR_PLATFORM=	NetBSD-*-i386
CHECK_SHLIBS=		NO		# this is Linux software

RESTRICTED=		"Redistribution not permitted"
LICENSE=		fee-based-commercial-use
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_BUILD=		YES

do-configure:
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" <${FILESDIR}/eagle >${WRKDIR}/eagle

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/eagle
	cd ${WRKSRC} && ${CP} -R ${WRKSRC}/* ${PREFIX}/eagle
	${INSTALL_SCRIPT} ${WRKDIR}/eagle ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

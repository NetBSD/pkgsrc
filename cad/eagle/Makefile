# $NetBSD: Makefile,v 1.6 2002/09/13 21:35:17 rh Exp $
#

DISTNAME=		eagle-4.09r2e
PKGNAME=		eagle-4.09r2
WRKSRC=			${WRKDIR}/${DISTNAME:C/.$//}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cadsoft.de/pub/program/4.09r2/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.cadsoft.de/
COMMENT=		easy to use printed circuit board editor

DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11

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

.include "../../emulators/suse_linux/Makefile.application"


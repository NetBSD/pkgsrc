# $NetBSD: Makefile,v 1.11 2004/02/25 01:09:25 xtraeme Exp $
#

DISTNAME=		eagle-4.11e
PKGNAME=		eagle-4.11
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cadsoft.de/pub/program/4.11/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.cadsoft.de/
COMMENT=		Easy to use printed circuit board editor

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386
CHECK_SHLIBS=		NO		# this is Linux software

RESTRICTED=		"Redistribution not permitted"
LICENSE=		fee-based-commercial-use
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/${DISTNAME:C/.$//}
NO_BUILD=		YES

do-configure:
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" <${FILESDIR}/eagle >${WRKDIR}/eagle

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/eagle
	cd ${WRKSRC} && ${CP} -R ${WRKSRC}/* ${PREFIX}/eagle
	${INSTALL_SCRIPT} ${WRKDIR}/eagle ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.24 2013/12/23 11:57:02 wiz Exp $

DISTNAME=		eagle-lin-eng-4.16r2
PKGNAME=		${DISTNAME:S/-lin-eng//}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.cadsoft.de/eagle/program/${PKGVERSION}/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cadsoft.de/
COMMENT=		Easy to use printed circuit board editor
LICENSE=		fee-based-commercial-use

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

BUILD_DIRS=		# empty
INSTALLATION_DIRS=	bin

do-configure:
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" <${FILESDIR}/eagle >${WRKDIR}/eagle

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/eagle
	cd ${WRKSRC} && ${CP} -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/eagle
	${INSTALL_SCRIPT} ${WRKDIR}/eagle ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

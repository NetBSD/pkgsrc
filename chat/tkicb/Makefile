# $NetBSD: Makefile,v 1.16 2006/08/26 21:48:06 minskim Exp $
#

DISTNAME=	icb.2.1.4
PKGNAME=	tkicb-2.1.4
PKGREVISION=	3
CATEGORIES=	chat x11
MASTER_SITES=	ftp://shoshin.armory.com/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.icb.net/
COMMENT=	TK interface to the ICB chat system

LICENSE=		generic-nonlicense
RESTRICTED=		Author wishes to handle distribution
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
USE_LANGUAGES=	# empty
USE_TOOLS+=	wish:run

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's,/usr/local/lib/icb,${PREFIX}/libdata/tkicb,g' \
		-e 's,wish8\.0,${WISH},g' < ${WRKSRC}/bin/icb \
		> ${WRKSRC}/bin/tkicb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tkicb ${PREFIX}/bin/tkicb
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/tkicb
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/tkicb/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/tkicb/lib
	${INSTALL_SCRIPT} ${WRKSRC}/icb.tcl ${PREFIX}/libdata/tkicb/icb.tcl
	${INSTALL_SCRIPT} ${WRKSRC}/tcl/*.tcl ${PREFIX}/libdata/tkicb/tcl
	${INSTALL_SCRIPT} ${WRKSRC}/lib/confuse ${WRKSRC}/lib/flirt \
		${WRKSRC}/lib/servers ${PREFIX}/libdata/tkicb/lib
	${INSTALL_SCRIPT} ${WRKSRC}/lib/* ${PREFIX}/libdata/tkicb/lib

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:26 hubertf Exp $
#

DISTNAME=	icb.2.1.4
PKGNAME=	tkicb-2.1.4
PKGREVISION=	1
CATEGORIES=	chat x11
MASTER_SITES=	ftp://shoshin.armory.com/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.icb.net/
COMMENT=	TK interface to the ICB chat system

RESTRICTED=		"Author wishes to handle distribution"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK_ONLY=	YES
USE_X11=	yes

WRKSRC=		${WRKDIR}

do-build:
	${SED} -e 's,/usr/local/lib/icb,${PREFIX}/libdata/tkicb,g' \
		-e 's,wish8\.0,${PREFIX}/bin/wish,g' < ${WRKSRC}/bin/icb \
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

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

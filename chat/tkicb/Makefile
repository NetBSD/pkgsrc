# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 00:36:36 wiz Exp $
#

DISTNAME=	icb.2.1.4
PKGNAME=	tkicb-2.1.4nb1
CATEGORIES=	chat x11
MASTER_SITES=	ftp://shoshin.armory.com/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.icb.net/

DEPENDS=	tk-8.3.2:../../x11/tk

RESTRICTED=		"Author wishes to handle distribution"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_X11=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

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

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 1998/11/20 09:43:57 frueauf Exp $
#

DISTNAME=	icb.2.1.4
PKGNAME=	tkicb-2.1.4
CATEGORIES=	x11 net
MASTER_SITES=	ftp://shoshin.armory.com/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@netbsd.org

DEPENDS=	tk-8.0p2:../../x11/tk80

DIST_SUBDIR=	tkicb
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

do-build:
	${SED} -e 's,/usr/local/lib/icb,${PREFIX}/libdata/tkicb,g' \
		-e 's,wish8\.0,${PREFIX}/bin/wish8.0,g' < ${WRKSRC}/bin/icb \
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

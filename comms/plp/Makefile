# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:17 rh Exp $

DISTNAME=	plp_1_8
PKGNAME=	plp-1.8
CATEGORIES=	comms
MASTER_SITES=	http://www.proudman51.freeserve.co.uk/psion/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.proudman51.freeserve.co.uk/psion/

USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/utils/libplputils.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ncp/ncp ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/rfsv/rfsv ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/plp

.include "../../mk/bsd.pkg.mk"

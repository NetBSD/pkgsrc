# $NetBSD: Makefile,v 1.1.1.1 1999/05/06 07:39:08 sakamoto Exp $
#

DISTNAME=	plp_1_7
PKGNAME=	plp-1.7
CATEGORIES=	comms
MASTER_SITES=	http://www.btinternet.com/~philip.proudman/psion/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	${MASTER_SITES}

USE_GMAKE=	yes
USE_LIBTOOL=	yes

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/utils/libplputils.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ncp/ncp ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/rfsv/rfsv ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/plp

.include "../../mk/bsd.pkg.mk"

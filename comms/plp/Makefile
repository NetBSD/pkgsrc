# $NetBSD: Makefile,v 1.11 2002/11/14 23:58:33 jlam Exp $

DISTNAME=	plp_1_8
PKGNAME=	plp-1.8
CATEGORIES=	comms
MASTER_SITES=	http://www.proudman51.freeserve.co.uk/psion/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.proudman51.freeserve.co.uk/psion/
COMMENT=	Tools to talk to the PSION organiser

USE_BUILDLINK2=	# defined
USE_CXX=	# defined
USE_GMAKE=	# defined
USE_LIBTOOL=	# defined

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/utils/libplputils.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ncp/ncp ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/rfsv/rfsv ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/plp

.include "../../mk/bsd.pkg.mk"

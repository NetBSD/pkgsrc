# $NetBSD: Makefile,v 1.10 2001/08/19 18:39:50 jlam Exp $

DISTNAME=	plp_1_8
PKGNAME=	plp-1.8
CATEGORIES=	comms
MASTER_SITES=	http://www.proudman51.freeserve.co.uk/psion/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.proudman51.freeserve.co.uk/psion/
COMMENT=	Tools to talk to the PSION organiser

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAKE_ENV+=	REALCXX="${CXX}"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/utils/libplputils.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ncp/ncp ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/rfsv/rfsv ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/plp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/plp

.include "../../mk/bsd.pkg.mk"

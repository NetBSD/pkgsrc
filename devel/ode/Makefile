# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 19:00:56 xtraeme Exp $
#

DISTNAME=	ode-0.039
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://opende.sourceforge.net/
COMMENT=	Library for the simulation of Rigid Body Dynamics

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes

do-configure:
	cd ${WRKSRC} && ${GMAKE} configure
do-build:
	cd ${WRKSRC} && ${GMAKE} ode-lib
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/ode
	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode
	${INSTALL_DATA} ${WRKSRC}/lib/libode.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"

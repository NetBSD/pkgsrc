# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=	ode-0.039
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://opende.sourceforge.net/
COMMENT=	Library for the simulation of Rigid Body Dynamics

USE_TOOLS+=	gmake

.include "../../mk/x11.buildlink3.mk"

INSTALLATION_DIRS=	lib

do-configure:
	cd ${WRKSRC} && ${GMAKE} configure
do-build:
	cd ${WRKSRC} && ${GMAKE} ode-lib
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/ode
	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode
	${INSTALL_DATA} ${WRKSRC}/lib/libode.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"

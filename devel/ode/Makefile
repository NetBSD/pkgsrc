# $NetBSD: Makefile,v 1.9 2006/01/24 22:45:33 rillig Exp $
#

DISTNAME=	ode-0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics

USE_TOOLS+=	gmake

.include "../../mk/x11.buildlink3.mk"

INSTALLATION_DIRS=	include/ode lib

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode
	${INSTALL_DATA} ${WRKSRC}/lib/libode.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"

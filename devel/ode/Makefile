# $NetBSD: Makefile,v 1.11 2006/02/10 20:35:28 adam Exp $

DISTNAME=	ode-0.5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=	ode-lib

INSTALLATION_DIRS=	include/ode lib

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libode.la \
		${PREFIX}/lib

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

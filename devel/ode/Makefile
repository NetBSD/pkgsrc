# $NetBSD: Makefile,v 1.15 2008/03/03 17:45:36 jlam Exp $

DISTNAME=	ode-0.5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=	ode-lib

INSTALLATION_DIRS=	include/ode lib

do-configure:
	cd ${WRKSRC} && ${MAKE_PROGRAM} configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h \
		${DESTDIR}${PREFIX}/include/ode
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libode.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2003/06/02 01:20:40 jschauma Exp $
#

DISTNAME=	libdockapp-0.4.0
CATEGORIES=	devel wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	simple library to create dockapps for WindowMaker

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libdockapp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libdockapp

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

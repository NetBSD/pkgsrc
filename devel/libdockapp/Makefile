# $NetBSD: Makefile,v 1.10 2003/07/21 16:43:26 martti Exp $
#

DISTNAME=	libdockapp-0.4.0
CATEGORIES=	devel wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	Simple library to create dockapps for WindowMaker

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

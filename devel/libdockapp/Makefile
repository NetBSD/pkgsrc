# $NetBSD: Makefile,v 1.1.1.1 2001/03/12 17:10:35 wiz Exp $
#

DISTNAME=	libdockapp-0.4.0
CATEGORIES=	devel wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	simple library to create dockapps for WindowMaker

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11=		YES
USE_XPM=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libdockapp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libdockapp

.include "../../mk/bsd.pkg.mk"

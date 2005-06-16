# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:51 jlam Exp $
#

DISTNAME=		lrmi-0.8
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lrmi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lrmi/
COMMENT=		Wrapper to the i386 vm86 mode

ONLY_FOR_PLATFORM=	*-*-i386
MAKEFILE=		Makefile.bsd
INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/vbe.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/liblrmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/vbetest ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2005/11/08 16:50:51 tv Exp $
#

DISTNAME=		lrmi-0.8
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lrmi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lrmi/
COMMENT=		Wrapper to the i386 vm86 mode

ONLY_FOR_PLATFORM=	*-*-i386
NOT_FOR_PLATFORM+=	Interix-*-* # cannot call real mode from Windows

MAKEFILE=		Makefile.bsd
INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/vbe.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/liblrmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/vbetest ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

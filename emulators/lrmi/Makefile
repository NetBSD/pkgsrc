# $NetBSD: Makefile,v 1.6 2005/04/05 10:41:43 wiz Exp $
#

DISTNAME=		lrmi-0.8
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lrmi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lrmi/
COMMENT=		Wrapper to the i386 vm86 mode

ONLY_FOR_PLATFORM=	*-*-i386
USE_BUILDLINK3=		yes
MAKEFILE=		Makefile.bsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/vbe.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/liblrmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/vbetest ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

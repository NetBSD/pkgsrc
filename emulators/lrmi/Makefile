# $NetBSD: Makefile,v 1.1.1.1 2003/08/11 18:13:50 drochner Exp $
#

DISTNAME=		lrmi-0.8
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lrmi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lrmi/
COMMENT=		Wrapper to the i386 vm86 mode

ONLY_FOR_PLATFORM=	*-*-i386
USE_BUILDLINK2=		yes
MAKEFILE=		Makefile.bsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblrmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/vbetest ${PREFIX}/bin
.include "../../mk/bsd.pkg.mk"

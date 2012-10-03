# $NetBSD: Makefile,v 1.13 2012/10/03 12:55:15 asau Exp $
#

DISTNAME=		lrmi-0.8
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lrmi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lrmi/
COMMENT=		Wrapper to the i386 vm86 mode

ONLY_FOR_PLATFORM=	*-*-i386
NOT_FOR_PLATFORM+=	Interix-*-* # cannot call real mode from Windows

MAKE_FILE=		Makefile.bsd
INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/vbe.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/liblrmi.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/liblrmi.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/vbetest ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2000/08/29 19:55:05 jwise Exp $

DISTNAME=	stooop-4.1.1
CATEGORIES=	x11 tcl
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://jfontain.free.fr/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.tcl ${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.tcl ${PREFIX}/lib/tcl/stooop
	${MKDIR} ${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.htm ${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.htm ${PREFIX}/share/doc/tcl/stooop

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 1999/06/07 22:14:08 tron Exp $

DISTNAME=	stooop-3.7
CATEGORIES=	x11 tcl80
MASTER_SITES=	http://www.multimania.com/jfontain/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mygale.org/~jfontain/

DEPENDS+=	tcl-8.0.5:../../lang/tcl80

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/stooop
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.tcl ${PREFIX}/lib/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.tcl ${PREFIX}/lib/stooop

.include "../../mk/bsd.pkg.mk"

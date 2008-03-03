# $NetBSD: Makefile,v 1.12 2008/03/03 17:45:37 jlam Exp $

DISTNAME=	stooop-4.1.1
CATEGORIES=	x11 tcl
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jfontain.free.fr/
COMMENT=	Simple Tcl Only Object Oriented Programming scheme

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${DESTDIR}${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.tcl ${DESTDIR}${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.tcl ${DESTDIR}${PREFIX}/lib/tcl/stooop
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/stooop.htm ${DESTDIR}${PREFIX}/share/doc/tcl/stooop
	${INSTALL_DATA} ${WRKSRC}/switched.htm ${DESTDIR}${PREFIX}/share/doc/tcl/stooop

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2012/10/23 18:16:57 asau Exp $
#

DISTNAME=		secpanel-0.5.1
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.pingx.net/secpanel/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.pingx.net/secpanel/
COMMENT=		GUI front-end for SSH

DEPENDS+=		tk>=8.4:../../x11/tk

NO_BUILD=		yes

INSTALLATION_DIRS+=	bin lib/secpanel/images

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/*.tcl ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/default.* ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/secpanel.* ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/images/*.gif ${DESTDIR}${PREFIX}/lib/secpanel/images/
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"

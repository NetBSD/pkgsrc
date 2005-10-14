# $NetBSD: Makefile,v 1.1.1.1 2005/10/14 01:06:20 minskim Exp $
#

DISTNAME=		secpanel-0.5.1
CATEGORIES=		security
MASTER_SITES=		http://www.pingx.net/secpanel/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.pingx.net/secpanel/
COMMENT=		GUI front-end for SSH

DEPENDS+=		tk>=8.4:../../x11/tk

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/secpanel
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/*.tcl ${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/default.* ${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/secpanel.* ${PREFIX}/lib/secpanel/
	${INSTALL_DATA_DIR} ${PREFIX}/lib/secpanel/images
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/images/*.gif ${PREFIX}/lib/secpanel/images/
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"

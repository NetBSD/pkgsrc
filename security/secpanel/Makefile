# $NetBSD: Makefile,v 1.5 2022/04/24 13:13:43 tnn Exp $
#

DISTNAME=		secpanel-0.6.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sln2/}
EXTRACT_SUFX=		.tgz
MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		https://web.archive.org/web/20210506224950/http://themediahost.de/secpanel/
COMMENT=		GUI front-end for SSH

DEPENDS+=		tk>=8.4:../../x11/tk

NO_BUILD=		yes

INSTALLATION_DIRS+=	bin lib/secpanel/images

WRKSRC=			${WRKDIR}/usr/local

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/*.tcl ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/*.txt ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/default.* ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/spdistkey ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/secpanel.* ${DESTDIR}${PREFIX}/lib/secpanel/
	${INSTALL_DATA} ${WRKSRC}/lib/secpanel/images/*.gif ${DESTDIR}${PREFIX}/lib/secpanel/images/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/secpanel ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"

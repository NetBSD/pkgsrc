# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 12:22:47 drochner Exp $
#

DISTNAME=		CIA_WDB2.jpd
PKGNAME=		xrmap-data-0
CATEGORIES=		geography
MASTER_SITES=		http://frmas.free.fr/files/
EXTRACT_SUFX=		.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Vector data for xrmap

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
NO_BUILD=		yes
DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

do-install:
	${INSTALL_DATA} ${WRKSRC}/CIA_WDB2.jpd ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2008/03/04 14:44:05 jlam Exp $
#

DISTNAME=		CIA_WDB2.jpd
PKGNAME=		xrmap-data-0
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://frmas.free.fr/files/
EXTRACT_SUFX=		.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Vector data for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	${INSTALL_DATA} ${WRKSRC}/CIA_WDB2.jpd ${DESTDIR}${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

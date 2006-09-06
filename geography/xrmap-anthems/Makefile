# $NetBSD: Makefile,v 1.6 2006/09/06 10:00:25 rillig Exp $
#

DISTNAME=		anthems-1.1
PKGNAME=		xrmap-anthems-1.1
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		National anthems (text) for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && pax -rw -pp anthems ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2016/02/26 14:05:14 jperkin Exp $
#

DISTNAME=		flags-1.1
PKGNAME=		xrmap-flags-1.1
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		National flags for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm flags ${DESTDIR}${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

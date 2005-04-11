# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:59 tv Exp $
#

DISTNAME=		hymns-1.2
PKGNAME=		xrmap-hymns-1.2
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		National anthems (MIDI) for xrmap

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe hymns ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

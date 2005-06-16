# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:56 jlam Exp $
#

DISTNAME=		anthems-1.1
PKGNAME=		xrmap-anthems-1.1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		National anthems (text) for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe anthems ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

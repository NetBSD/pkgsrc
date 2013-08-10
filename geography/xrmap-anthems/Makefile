# $NetBSD: Makefile,v 1.10 2013/08/10 12:45:15 shattered Exp $
#

DISTNAME=		anthems-1.3
PKGNAME=		xrmap-anthems-1.3
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		National anthems (text) for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap
USE_TOOLS+=		pax

do-install:
	cd ${WRKSRC} && pax -rw -pp * ${DESTDIR}${PREFIX}/share/rmap/anthems

.include "../../mk/bsd.pkg.mk"

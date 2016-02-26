# $NetBSD: Makefile,v 1.12 2016/02/26 14:05:14 jperkin Exp $
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
INSTALLATION_DIRS=	share/rmap/anthems
USE_TOOLS+=		pax

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm * ${DESTDIR}${PREFIX}/share/rmap/anthems

.include "../../mk/bsd.pkg.mk"

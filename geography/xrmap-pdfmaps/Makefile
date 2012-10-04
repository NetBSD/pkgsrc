# $NetBSD: Makefile,v 1.8 2012/10/04 09:19:22 asau Exp $
#

DISTNAME=		pdfmaps-1.1
PKGNAME=		xrmap-pdfmaps-1.1
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		PDF maps for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && pax -rw -pe pdfmaps ${DESTDIR}${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

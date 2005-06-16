# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:57 jlam Exp $
#

DISTNAME=		factbook_text_2002
PKGNAME=		xrmap-factbook_text-2002
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		CIA factbook for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe factbook ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 12:24:06 drochner Exp $
#

DISTNAME=		factbook_html_2002
PKGNAME=		xrmap-factbook_html-2002
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		CIA factbook for xrmap (HTML)

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
NO_BUILD=		yes
DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe factbook ${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

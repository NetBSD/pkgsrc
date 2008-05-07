# $NetBSD: Makefile,v 1.7 2008/05/07 19:32:54 drochner Exp $
#

DISTNAME=		factbook_text_2006
PKGNAME=		xrmap-factbook_text-2006
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		CIA factbook for xrmap

DEPENDS+=		xrmap-base>=2.29:../../geography/xrmap-base

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/rmap

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe factbook ${DESTDIR}${PREFIX}/share/rmap

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.10 2009/08/03 14:28:31 joerg Exp $

DISTNAME=		Isearch-1.47.01
PKGNAME=		isearch-1.47.01
CATEGORIES=		textproc databases
MASTER_SITES=		http://www.etymon.com/pub/Isearch/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.etymon.com/Isearch/
COMMENT=		Advanced text indexing and searching system

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	share/doc/isearch share/doc/html/isearch

post-install:
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DESTDIR}${PREFIX}/share/doc/html/isearch/

.include "../../mk/bsd.pkg.mk"

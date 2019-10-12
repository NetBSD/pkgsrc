# $NetBSD: Makefile,v 1.17 2019/10/12 21:14:22 rillig Exp $

DISTNAME=		Isearch-1.47.01
PKGNAME=		isearch-1.47.01
PKGREVISION=		2
CATEGORIES=		textproc databases
MASTER_SITES=		# http://www.etymon.com/pub/Isearch/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.etymon.com/Isearch/
COMMENT=		Advanced text indexing and searching system

# isearch-1.47.01 doesn't declare the dependencies correctly
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin share/doc/isearch

post-install:
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/doc/DebugFirewall.doc ${DESTDIR}${PREFIX}/share/doc/isearch
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DESTDIR}${PREFIX}/share/doc/isearch/

.include "../../mk/bsd.pkg.mk"

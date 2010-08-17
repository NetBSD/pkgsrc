# $NetBSD: Makefile,v 1.7 2010/08/17 11:24:20 obache Exp $
#

DISTNAME=		mapm-4.9.5a
CATEGORIES=		math
MASTER_SITES=		http://www.tc.umn.edu/~ringx004/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tc.umn.edu/~ringx004/
COMMENT=		Arbitrary Precision Math library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/_/}

DOCS=	README algorithms.used function.ref article.pdf

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin include lib share/doc/mapm

do-install:
	${INSTALL_DATA} ${WRKSRC}/m_apm.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libmapm.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/calc ${DESTDIR}${PREFIX}/bin/mapm-calc
	cd ${WRKSRC}/DOCS; for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/doc/mapm; \
	done

.include "../../mk/bsd.pkg.mk"

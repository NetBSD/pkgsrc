# $NetBSD: Makefile,v 1.8 2010/09/01 10:54:31 drochner Exp $
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

do-test:
	cd ${WRKSRC} && ./validate

.include "../../mk/bsd.pkg.mk"

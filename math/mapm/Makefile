# $NetBSD: Makefile,v 1.5 2006/06/02 13:42:52 joerg Exp $
#

DISTNAME=		mapm-4.9.2
CATEGORIES=		math
MASTER_SITES=		http://www.tc.umn.edu/~ringx004/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tc.umn.edu/~ringx004/
COMMENT=		Arbitrary Precision Math library

WRKSRC=		${WRKDIR}/mapm_4.9.2

DOCS=	README algorithms.used function.ref

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin include lib share/doc/mapm

do-install:
	${INSTALL_DATA} ${WRKSRC}/m_apm.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libmapm.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/calc ${PREFIX}/bin/mapm-calc
	cd ${WRKSRC}; for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/mapm; \
	done

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:04 jlam Exp $
#

DISTNAME=		mapm-4.9.2
CATEGORIES=		math
MASTER_SITES=		http://www.tc.umn.edu/~ringx004/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tc.umn.edu/~ringx004/
COMMENT=		Arbitrary Precision Math library

WRKSRC=		${WRKDIR}/mapm_4.9.2

DOCS=	README algorithms.used function.ref

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/m_apm.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libmapm.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/calc ${PREFIX}/bin/mapm-calc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mapm
	cd ${WRKSRC}; for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/mapm; \
	done

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2004/07/22 17:33:28 drochner Exp $
#

DISTNAME=		mapm-4.9.2
CATEGORIES=		math
MASTER_SITES=		http://www.tc.umn.edu/~ringx004/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tc.umn.edu/~ringx004/
COMMENT=		Arbitrary Precision Math library

WRKSRC=		${WRKDIR}/mapm_4.9.2
USE_BUILDLINK3=		yes

DOCS=	README algorithms.used function.ref

do-install:
	${INSTALL_DATA} ${WRKSRC}/m_apm.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libmapm.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/calc ${PREFIX}/bin/mapm-calc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mapm
	cd ${WRKSRC}; for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/mapm; \
	done

.include "../../mk/bsd.pkg.mk"

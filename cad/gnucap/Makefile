# $NetBSD: Makefile,v 1.6 2003/07/21 16:32:11 martti Exp $
#

DISTNAME=	gnucap-0.33
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=gnucap/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/tools/acs/index.html
COMMENT=	General purpose circuit simulator

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_GNU_READLINE=	YES

do-build:
	@cd ${WRKSRC}/modelgen && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${LOWER_OPSYS}
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*/gnucap ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/man.pdf ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/man/* ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnucap
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/gnucap

do-test:
	cd ${WRKSRC}/test && ./test ../src/*/gnucap "" 0001 ==

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

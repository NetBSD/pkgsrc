# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	gnucap-0.34
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/ \
		http://www.geda.seul.org/dist/ \
		http://www.kettering.edu/~adavis/gnucap/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnucap.org
COMMENT=	General purpose circuit simulator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	YES

do-build:
	@cd ${WRKSRC}/modelgen && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} pkgsrc
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} pkgsrc

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/*/gnucap ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/gnucap-man.pdf ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/html/* ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnucap
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/gnucap

do-test:
	cd ${WRKSRC}/test && ./test ../src/*/gnucap "" 0001 ==

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

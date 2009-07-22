# $NetBSD: Makefile,v 1.3 2009/07/22 09:01:43 wiz Exp $

DISTNAME=	algorithm2e
PKGNAME=	tex-${DISTNAME}-3.9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/help/Catalogue/entries/algorithm2e.html
COMMENT=	Environment for writing algorithms

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e.pdf \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e_ex*.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/algorithm2e

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2006/04/09 21:45:51 minskim Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-1.618
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/memoir/
COMMENT=	Typeset fiction, non-fiction, and mathematical books

USE_DIRS+=	texmf-1.0

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex memoir.ins

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/memoir
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/memman.pdf \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/memoir
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/memoir
	${INSTALL_DATA} ${WRKSRC}/*.cl? ${WRKSRC}/*.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/memoir

.include "../../mk/bsd.pkg.mk"

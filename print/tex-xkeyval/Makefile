# $NetBSD: Makefile,v 1.1.1.1 2007/05/25 11:53:15 jmmv Exp $

DISTNAME=	xkeyval
PKGNAME=	tex-${DISTNAME}-2.5f
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/help/Catalogue/entries/xkeyval.html
COMMENT=	Macros for setting keys and class or package options

NO_BUILD=	yes
USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/xkeyval
	${INSTALL_DATA} ${WRKSRC}/doc/xkeyval.pdf \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/xkeyval
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/generic/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/keyval.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/generic/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/pst-xkey.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/generic/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/xkeyval.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/generic/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/xkvtxhdr.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/generic/xkeyval
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/pst-xkey.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/xkeyval.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/xkvltxp.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/xkeyval
	${INSTALL_DATA} ${WRKSRC}/run/xkvview.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/xkeyval

.include "../../mk/bsd.pkg.mk"

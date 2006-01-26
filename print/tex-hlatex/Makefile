# $NetBSD: Makefile,v 1.6 2006/01/26 03:57:55 minskim Exp $

DISTNAME=	HLaTeX-1.0.1
PKGNAME=	tex-hlatex-${DISTNAME:S/HLaTeX-//}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/hlatex/
COMMENT=	LaTeX package to typeset Hangul

DEPENDS+=	tex-uhc-fonts-base>=1.0:../../fonts/tex-uhc-fonts-base

WRKSRC=		${WRKDIR}/HLaTeX

.include "../../print/teTeX/module.mk"

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} -o ${WRKSRC}/hbibtex \
		${WRKSRC}/contrib/hbibtex.c
	${CC} ${CPPFLAGS} ${CFLAGS} -o ${WRKSRC}/hmakeindex \
		${WRKSRC}/contrib/hmakeindex.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hbibtex ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/hmakeindex ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex
	${INSTALL_DATA} ${WRKSRC}/latex/* \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/hbname-k.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.sty ${WRKSRC}/contrib/hfn-k.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex
.for f in u8hangul.tex uhc-test.tex uhc*.fd
	${INSTALL_DATA} ${WRKSRC}/lambda/${f} \
		${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/hbname-u.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/hfn-u.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/omega/ocp/hlatex
	${INSTALL_DATA} ${WRKSRC}/lambda/hlatex.ocp \
		${PKG_LOCALTEXMFPREFIX}/omega/ocp/hlatex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/omega/otp/hlatex
	${INSTALL_DATA} ${WRKSRC}/lambda/hlatex.otp \
		${PKG_LOCALTEXMFPREFIX}/omega/otp/hlatex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/bibtex/bst/hlatex
	${INSTALL_DATA} ${WRKSRC}/contrib/halpha.bst \
		${PKG_LOCALTEXMFPREFIX}/bibtex/bst/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.ist \
		${PKG_LOCALTEXMFPREFIX}/makeindex/

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2005/11/15 07:11:53 minskim Exp $

DISTNAME=	HLaTeX-1.0.1
PKGNAME=	tex-hlatex-${DISTNAME:S/HLaTeX-//}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} uhc-fonts-1.0.tar.gz \
		${HLATEX_FONTS}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ftp.ktug.or.kr/mirrors/HLaTeX/hlatex.html
COMMENT=	LaTeX package to typeset Hangul

SITES_uhc-fonts-1.0.tar.gz=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/fonts/
SITES_uhc-myoungjo-1.0.tar.gz=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/fonts/
SITES_uhc-gothic-1.0.tar.gz=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/fonts/
SITES_uhc-taza-1.0.tar.gz=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/fonts/

TEX_ACCEPTED=	teTeX3

BUILDLINK_DEPENDS.teTeX-bin+=	teTeX-bin>=3.0nb4

WRKSRC=		${WRKDIR}/HLaTeX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} uhc-fonts-1.0.tar.gz

HLATEX_FONTS=	uhc-myoungjo-1.0.tar.gz \
		uhc-gothic-1.0.tar.gz \
		uhc-taza-1.0.tar.gz

TEXFONTMAPS=	uhc-base.map

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
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/map/hlatex
	${INSTALL_DATA} ${WRKDIR}/uhc-fonts-1.0/uhc-base.map \
		${PKG_LOCALTEXMFPREFIX}/fonts/map/hlatex/
.for f in ${HLATEX_FONTS}
	extract_file=${_DISTDIR:Q}/${f}; \
	cd ${PKG_LOCALTEXMFPREFIX}/fonts; ${EXTRACT_CMD.tar.gz}
.endfor

.include "../../mk/bsd.pkg.mk"

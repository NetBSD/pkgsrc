# $NetBSD: Makefile,v 1.10 2009/08/18 15:43:58 joerg Exp $

DISTNAME=	HLaTeX-1.0.1
PKGNAME=	tex-hlatex-${DISTNAME:S/HLaTeX-//}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/hlatex/
COMMENT=	LaTeX package to typeset Hangul

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tex-uhc-fonts-base>=1.0:../../fonts/tex-uhc-fonts-base

WRKSRC=		${WRKDIR}/HLaTeX

.include "../../print/teTeX/module.mk"

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} -o ${WRKSRC}/hbibtex \
		${WRKSRC}/contrib/hbibtex.c
	${CC} ${CPPFLAGS} ${CFLAGS} -o ${WRKSRC}/hmakeindex \
		${WRKSRC}/contrib/hmakeindex.c

INSTALLATION_DIRS=	bin \
			${PKG_LOCALTEXMFPREFIX}/bibtex/bst/hlatex \
			${PKG_LOCALTEXMFPREFIX}/omega/ocp/hlatex \
			${PKG_LOCALTEXMFPREFIX}/omega/otp/hlatex \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex \
			${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex \
			${PKG_LOCALTEXMFPREFIX}/makeindex/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hbibtex ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/hmakeindex ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/latex/* \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/hbname-k.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.sty ${WRKSRC}/contrib/hfn-k.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/hlatex/
.for f in u8hangul.tex uhc-test.tex uhc*.fd
	${INSTALL_DATA} ${WRKSRC}/lambda/${f} \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/hbname-u.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/hfn-u.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/lambda/hlatex/
	${INSTALL_DATA} ${WRKSRC}/lambda/hlatex.ocp \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/omega/ocp/hlatex/
	${INSTALL_DATA} ${WRKSRC}/lambda/hlatex.otp \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/omega/otp/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/halpha.bst \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/bibtex/bst/hlatex/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.ist \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/makeindex/

.include "../../mk/bsd.pkg.mk"

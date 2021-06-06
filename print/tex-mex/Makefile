# $NetBSD: Makefile,v 1.6 2021/06/06 21:59:15 markd Exp $

DISTNAME=	mex
PKGNAME=	tex-${DISTNAME}-1.05a
TEXLIVE_REV=	58661

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mex
COMMENT=	Polish formats for TeX
LICENSE=	public-domain

DEPENDS+=	tex-enctex-[0-9]*:../../print/tex-enctex
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-utf8mex-[0-9]*:../../print/tex-utf8mex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"mex pdftex mexconf.tex -translate-file=cp227.tcx *mex.ini\\npdfmex pdftex mexconf.tex -translate-file=cp227.tcx *pdfmex.ini\\n"
#utf8mex pdftex mexconf.tex -translate-file=cp227.tcx *utf8mex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfmex
#	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/utf8mex

.include "../../mk/bsd.pkg.mk"

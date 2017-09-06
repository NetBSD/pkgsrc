# $NetBSD: Makefile,v 1.2 2017/09/06 16:49:40 wiz Exp $

DISTNAME=	mex
PKGNAME=	tex-${DISTNAME}-1.05
TEXLIVE_REV=	40855

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mex
COMMENT=	Polish formats for TeX
LICENSE=	public-domain

DEPENDS+=	tex-pl-[0-9]*:../../fonts/tex-pl
DEPENDS+=	tex-hyphen-polish-[0-9]*:../../print/tex-hyphen-polish
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
#DEPENDS+=	tex-utf8mex-[0-9]*:../../print/tex-utf8mex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"mex pdftex mexconf.tex -translate-file=cp227.tcx *mex.ini\\npdfmex pdftex mexconf.tex -translate-file=cp227.tcx *pdfmex.ini\\n"
#utf8mex pdftex mexconf.tex -translate-file=cp227.tcx *utf8mex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfmex
#	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/utf8mex

.include "../../mk/bsd.pkg.mk"

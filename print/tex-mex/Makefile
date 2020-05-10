# $NetBSD: Makefile,v 1.5 2020/05/10 04:32:05 markd Exp $

DISTNAME=	mex
PKGNAME=	tex-${DISTNAME}-1.05
PKGREVISION=	1
TEXLIVE_REV=	40855

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mex
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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfmex
#	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/utf8mex

.include "../../mk/bsd.pkg.mk"

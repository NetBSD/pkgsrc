# $NetBSD: Makefile,v 1.1 2013/10/19 20:43:39 markd Exp $

DISTNAME=	mltex
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	30214

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The MLTeX system

CONFLICTS+=	teTeX-texmf<=3.0nb42
DEPENDS+=	tex-latex>=2012:../../print/tex-latex

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"mltex pdftex language.dat -translate-file=cp227.tcx *mltex.ini\\nmllatex pdftex language.dat -translate-file=cp227.tcx *mllatex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mllatex

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2024/03/24 10:51:36 markd Exp $

DISTNAME=	mltex
PKGNAME=	tex-${DISTNAME}-2.2.70002
TEXLIVE_REV=	70002

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mltex
COMMENT=	The MLTeX system

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"mltex pdftex language.dat -translate-file=cp227.tcx *mltex.ini\\nmllatex pdftex language.dat -translate-file=cp227.tcx *mllatex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mllatex

.include "../../mk/bsd.pkg.mk"

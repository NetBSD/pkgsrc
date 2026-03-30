# $NetBSD: Makefile,v 1.19 2026/03/30 08:44:52 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-3.8.0
TEXLIVE_REV=	78270

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/minted
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c AND modified-bsd

DEPENDS+=	tex-catchfile-[0-9]*:../../print/tex-catchfile
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-fvextra-[0-9]*:../../print/tex-fvextra
DEPENDS+=	tex-latex2pydata-[0-9]*:../../devel/tex-latex2pydata
DEPENDS+=	tex-newfloat-[0-9]*:../../print/tex-newfloat
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-pgfopts-[0-9]*:../../devel/tex-pgfopts
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-upquote-[0-9]*:../../print/tex-upquote
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

REPLACE_PYTHON+=	texmf-dist/scripts/minted/latexminted.py

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/minted/latexminted.py ${DESTDIR}${PREFIX}/bin/latexminted

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

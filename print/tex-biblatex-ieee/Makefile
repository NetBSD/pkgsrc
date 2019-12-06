# $NetBSD: Makefile,v 1.4 2019/12/06 20:18:59 markd Exp $

DISTNAME=	biblatex-ieee
PKGNAME=	tex-${DISTNAME}-1.3a
TEXLIVE_REV=	51402

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/biblatex-ieee
COMMENT=	IEEE style files for BibLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-biblatex-[0-9]*:../../print/tex-biblatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

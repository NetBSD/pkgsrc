# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:30 wiz Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.42
TEXLIVE_REV=	44798

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/beamer
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c OR gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

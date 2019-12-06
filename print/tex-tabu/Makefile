# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:23 markd Exp $

DISTNAME=	tabu
PKGNAME=	tex-${DISTNAME}-2.9
TEXLIVE_REV=	49707

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tabu
COMMENT=	Flexible LaTeX tabulars
LICENSE=	lppl-1.3c

DEPENDS+=	tex-varwidth-[0-9]*:../../print/tex-varwidth

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

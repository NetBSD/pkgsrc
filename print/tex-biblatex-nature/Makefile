# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:42 rillig Exp $

DISTNAME=	biblatex-nature
PKGNAME=	tex-${DISTNAME}-1.3c
TEXLIVE_REV=	48940

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/biblatex-nature
COMMENT=	BibLaTeX support for Nature
LICENSE=	lppl-1.3c

DEPENDS+=	tex-biblatex-[0-9]*:../../print/tex-biblatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

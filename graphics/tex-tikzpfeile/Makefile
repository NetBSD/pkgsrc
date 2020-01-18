# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:36 rillig Exp $

DISTNAME=	tikzpfeile
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	25777

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzpfeile
COMMENT=	Draw arrows using PGF/TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

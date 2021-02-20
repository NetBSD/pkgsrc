# $NetBSD: Makefile,v 1.6 2021/02/20 10:38:29 markd Exp $

DISTNAME=	polytable
PKGNAME=	tex-${DISTNAME}-0.8.6
TEXLIVE_REV=	55837

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/polytable
COMMENT=	Tabular-like environments with named columns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-lazylist>=1.0a:../../print/tex-lazylist
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

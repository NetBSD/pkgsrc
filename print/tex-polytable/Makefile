# $NetBSD: Makefile,v 1.4 2016/01/27 09:46:17 markd Exp $

DISTNAME=	polytable
PKGNAME=	tex-${DISTNAME}-0.8.5
TEXLIVE_REV=	31235

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tabular-like environments with named columns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-lazylist>=1.0a:../../print/tex-lazylist
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

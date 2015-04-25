# $NetBSD: Makefile,v 1.3 2015/04/25 04:19:00 markd Exp $

DISTNAME=	polytable
PKGNAME=	tex-${DISTNAME}-0.8.5
TEXLIVE_REV=	31235

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tabular-like environments with named columns

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-lazylist>=1.0a:../../print/tex-lazylist
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

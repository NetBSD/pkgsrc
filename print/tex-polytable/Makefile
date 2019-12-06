# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:05 markd Exp $

DISTNAME=	polytable
PKGNAME=	tex-${DISTNAME}-0.8.5
TEXLIVE_REV=	31235

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tabular-like environments with named columns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-lazylist>=1.0a:../../print/tex-lazylist
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

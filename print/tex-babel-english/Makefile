# $NetBSD: Makefile,v 1.5 2025/05/07 12:23:34 markd Exp $

DISTNAME=	babel-english
PKGNAME=	tex-${DISTNAME}-3.3r
TEXLIVE_REV=	70799

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-english
COMMENT=	Babel support for English
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel
DEPENDS+=	tex-hyphen-english-[0-9]*:../../print/tex-hyphen-english

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

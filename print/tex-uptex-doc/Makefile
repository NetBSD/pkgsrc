# $NetBSD: Makefile,v 1.1 2021/02/22 10:17:56 markd Exp $

DISTNAME=	uptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	56291

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uptex
COMMENT=	Documentation for tex-uptex
LICENSE=	modified-bsd

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.15 2023/06/17 10:13:12 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.3.67372
TEXLIVE_REV=	67372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

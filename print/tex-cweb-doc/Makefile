# $NetBSD: Makefile,v 1.10 2021/06/06 11:58:20 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.2
TEXLIVE_REV=	57972

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2022/09/01 10:26:59 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.3.63787
TEXLIVE_REV=	63787

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

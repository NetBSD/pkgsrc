# $NetBSD: Makefile,v 1.16 2024/02/03 04:39:45 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.3.69586
TEXLIVE_REV=	69586

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cwebbin
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

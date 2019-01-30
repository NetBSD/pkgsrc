# $NetBSD: Makefile,v 1.10 2019/01/30 06:16:44 markd Exp $

DISTNAME=	glossaries.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.42
TEXLIVE_REV=	49618

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/glossaries
COMMENT=	Documentation for tex-glossaries
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

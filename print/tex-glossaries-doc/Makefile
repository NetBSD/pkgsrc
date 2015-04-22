# $NetBSD: Makefile,v 1.3 2015/04/22 22:42:18 markd Exp $

DISTNAME=	glossaries.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.15
TEXLIVE_REV=	36533

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-glossaries
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

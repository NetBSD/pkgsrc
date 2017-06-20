# $NetBSD: Makefile,v 1.3 2017/06/20 22:07:26 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.64b
TEXLIVE_REV=	44166

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cweb
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

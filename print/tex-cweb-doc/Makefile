# $NetBSD: Makefile,v 1.2 2016/06/16 04:06:02 markd Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.64af
TEXLIVE_REV=	40768

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2012/03/05 16:20:36 minskim Exp $

DISTNAME=	cweb.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.64ad
TEXLIVE_REV=	23089

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-cweb

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS+=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

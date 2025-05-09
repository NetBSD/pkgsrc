# $NetBSD: Makefile,v 1.6 2025/05/09 22:36:29 markd Exp $

DISTNAME=	aramaic-serto.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3.2
TEXLIVE_REV=	74548

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/aramaic-serto
COMMENT=	Documentation for tex-aramaic-serto
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/aramaic-serto/serto.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

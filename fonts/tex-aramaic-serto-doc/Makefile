# $NetBSD: Makefile,v 1.2 2015/05/31 03:21:15 markd Exp $

DISTNAME=	aramaic-serto.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	30042

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/aramaic-serto
COMMENT=	Documentation for tex-aramaic-serto
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/aramaic-serto/serto.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

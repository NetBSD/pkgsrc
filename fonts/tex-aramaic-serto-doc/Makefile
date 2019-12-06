# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:32 markd Exp $

DISTNAME=	aramaic-serto.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	30042

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/aramaic-serto
COMMENT=	Documentation for tex-aramaic-serto
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/aramaic-serto/serto.py

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

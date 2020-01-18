# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:47 rillig Exp $

DISTNAME=	phaistos.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	18651

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/phaistos
COMMENT=	Documentation for tex-phaistos
LICENSE=	lppl-1.3c

REPLACE_PERL+=			doc/fonts/phaistos/getglyphs
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/phaistos/getglyphs

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

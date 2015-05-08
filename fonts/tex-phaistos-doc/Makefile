# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:52 wiz Exp $

DISTNAME=	phaistos.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	18651

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/phaistos
COMMENT=	Documentation for tex-phaistos
LICENSE=	lppl-1.3c

REPLACE_PERL+=			doc/fonts/phaistos/getglyphs
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/phaistos/getglyphs

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

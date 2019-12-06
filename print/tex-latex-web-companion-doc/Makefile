# $NetBSD: Makefile,v 1.4 2019/12/06 20:21:51 markd Exp $

DISTNAME=	latex-web-companion.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
PKGREVISION=	1
TEXLIVE_REV=	29349

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lwc-examples
COMMENT=	Examples from The LaTeX Web Companion
LICENSE=	lppl-1.3c

REPLACE_PERL+=			doc/latex/latex-web-companion/ch7/sgmlspl.pl
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/latex-web-companion/ch7/sgmlspl.pl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

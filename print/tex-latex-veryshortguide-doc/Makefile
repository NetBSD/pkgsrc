# $NetBSD: Makefile,v 1.4 2019/12/06 20:21:51 markd Exp $

DISTNAME=	latex-veryshortguide.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
PKGREVISION=	1
TEXLIVE_REV=	29803

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-veryshortguide
COMMENT=	The Very Short Guide to LaTeX
LICENSE=	lppl-1.3c

REPLACE_SH+=	doc/latex/latex-veryshortguide/build

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

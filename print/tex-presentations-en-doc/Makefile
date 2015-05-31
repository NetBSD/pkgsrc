# $NetBSD: Makefile,v 1.2 2015/05/31 11:40:18 wiz Exp $

DISTNAME=	presentations-en.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
PKGREVISION=	1
TEXLIVE_REV=	29803

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/presentations-en
COMMENT=       	Examples from the book Presentations with LaTeX
LICENSE=	lppl-1.3c

REPLACE_SH+=	doc/latex/presentations-en/runAll

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

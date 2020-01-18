# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:54 rillig Exp $

DISTNAME=	tengwarscript.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3.1
TEXLIVE_REV=	34594

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tengwarscript
COMMENT=	Documentation for tex-tengwarscript
LICENSE=	lppl-1.3c

REPLACE_SH=	doc/latex/tengwarscript/install-tengwar-scripts.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

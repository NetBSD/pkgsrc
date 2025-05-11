# $NetBSD: Makefile,v 1.5 2025/05/11 00:18:42 markd Exp $

DISTNAME=	xepersian.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-25.2.2
TEXLIVE_REV=	73697

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Documentation for tex-xepersian
LICENSE=	lppl-1.3c

REPLACE_PYTHON+=	doc/xelatex/xepersian/*.py

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

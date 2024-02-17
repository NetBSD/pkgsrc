# $NetBSD: Makefile,v 1.4 2024/02/17 04:22:36 markd Exp $

DISTNAME=	xepersian.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-25.0
TEXLIVE_REV=	68117

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Documentation for tex-xepersian
LICENSE=	lppl-1.3c

REPLACE_PYTHON+=	doc/xelatex/xepersian/*.py

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

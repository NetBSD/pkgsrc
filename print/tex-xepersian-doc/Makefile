# $NetBSD: Makefile,v 1.6 2026/03/31 19:58:33 markd Exp $

DISTNAME=	xepersian.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-26.01.01
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Documentation for tex-xepersian
LICENSE=	lppl-1.3c

REPLACE_PYTHON+=	doc/latex/xepersian/*.py

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

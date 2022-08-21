# $NetBSD: Makefile,v 1.1 2022/08/21 17:12:04 wiz Exp $

DISTNAME=	xepersian.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-24.7
TEXLIVE_REV=	63791

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Documentation for tex-xepersian
LICENSE=	lppl-1.3c

REPLACE_PYTHON+=	doc/xelatex/xepersian/*.py

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

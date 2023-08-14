# $NetBSD: Makefile,v 1.3 2023/08/14 05:25:07 wiz Exp $

DISTNAME=	xepersian.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-24.8
PKGREVISION=	1
TEXLIVE_REV=	64872

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Documentation for tex-xepersian
LICENSE=	lppl-1.3c

REPLACE_PYTHON+=	doc/xelatex/xepersian/*.py

.include "../../lang/python/application.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"

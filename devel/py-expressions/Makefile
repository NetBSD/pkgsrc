# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:02 wiz Exp $

DISTNAME=	expressions-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://databrewery.org/
COMMENT=	Extensible arithmetic expression parser and compiler
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-grako>=3.9.3:../../devel/py-grako

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2021/11/14 08:36:45 adam Exp $

DISTNAME=	gast-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gast/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/serge-sans-paille/gast
COMMENT=	Python AST that abstracts the underlying Python version
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-astunparse-[0-9]*:../../devel/py-astunparse

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

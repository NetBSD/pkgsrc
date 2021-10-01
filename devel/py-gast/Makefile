# $NetBSD: Makefile,v 1.1 2021/10/01 19:52:08 adam Exp $

DISTNAME=	gast-0.5.2
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

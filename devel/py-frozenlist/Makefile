# $NetBSD: Makefile,v 1.3 2022/08/07 08:03:35 wiz Exp $

DISTNAME=	frozenlist-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozenlist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/frozenlist
COMMENT=	List-like structure which implements collections.abc.MutableSequence
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

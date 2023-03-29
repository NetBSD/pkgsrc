# $NetBSD: Makefile,v 1.10 2023/03/29 09:34:11 wiz Exp $

DISTNAME=	immutables-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/immutables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/immutables
COMMENT=	Immutable collections
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.942:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.4:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 307
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

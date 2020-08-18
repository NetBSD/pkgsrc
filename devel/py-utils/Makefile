#	$NetBSD: Makefile,v 1.1 2020/08/18 20:18:56 riastradh Exp $

DISTNAME=	python-utils-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^python-//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-utils
COMMENT=	Some convenient utilities not included with standard Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

# pytest chokes on pytest.ini
pre-test:
	${RUN} cd ${WRKSRC} && \
	${RM} -f pytest.ini

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} PYTHONPATH=${WRKSRC}/build/lib \
	pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

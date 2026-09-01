# $NetBSD: Makefile,v 1.124 2026/09/01 13:49:19 adam Exp $

DISTNAME=	ipython-9.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator>=5.1.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-ipython-pygments-lexers>=1.0.0:../../devel/py-ipython-pygments-lexers
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.18.2:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-matplotlib-inline>=0.1.6:../../graphics/py-matplotlib-inline
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.6:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.41:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-psutil>=7:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.14.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-stack-data>=0.6.0:../../sysutils/py-stack-data
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.13.0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-pickleshare>=0:../../databases/py-pickleshare
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	ipython ipython3

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.120 2026/02/06 09:21:39 adam Exp $

DISTNAME=	ipython-9.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.3.2:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-ipython-pygments-lexers>=1.0.0:../../devel/py-ipython-pygments-lexers
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.18.1:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-matplotlib-inline>=0.1.5:../../graphics/py-matplotlib-inline
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.4:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.41:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.11.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-stack-data>=0.6.0:../../sysutils/py-stack-data
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.13.0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
	${MV} bin/ipython3 bin/ipython3-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

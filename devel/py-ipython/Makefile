# $NetBSD: Makefile,v 1.31 2018/11/21 17:31:50 adam Exp $

DISTNAME=	ipython-7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-backcall-[0-9]*:../../devel/py-backcall
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.10:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2.0.0:../../devel/py-prompt_toolkit2
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>0.8:../../devel/py-simplegeneric
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${RM} bin/iptest3 bin/ipython3 && \
	${MV} bin/iptest bin/iptest-${PYVERSSUFFIX} && \
	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

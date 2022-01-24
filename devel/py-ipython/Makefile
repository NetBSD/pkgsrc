# $NetBSD: Makefile,v 1.73 2022/01/24 18:37:58 adam Exp $

DISTNAME=	ipython-8.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-backcall-[0-9]*:../../devel/py-backcall
DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.16:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-matplotlib-inline>0:../../graphics/py-matplotlib-inline
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.4:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-stack-data-[0-9]*:../../sysutils/py-stack-data
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5:../../devel/py-traitlets
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == Darwin
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
	${MV} bin/ipython3 bin/ipython3-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

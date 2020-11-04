# $NetBSD: Makefile,v 1.56 2020/11/04 10:08:14 adam Exp $

DISTNAME=	ipython-7.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-backcall-[0-9]*:../../devel/py-backcall
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.16:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.2:../../devel/py-prompt_toolkit2
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == Darwin
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${RM} bin/iptest3 bin/ipython3 && \
	${MV} bin/iptest bin/iptest-${PYVERSSUFFIX} && \
	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

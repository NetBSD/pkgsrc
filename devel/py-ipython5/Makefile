# $NetBSD: Makefile,v 1.8 2021/04/06 14:36:48 adam Exp $

DISTNAME=	ipython-5.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

.include "../../lang/python/distutils.mk"

.if ${PYPKGPREFIX} == py27
DEPENDS+=	${PYPKGPREFIX}-backports.shutil_get_terminal_size-[0-9]*:../../devel/py-backports.shutil_get_terminal_size
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-scandir-[0-9]*:../../devel/py-scandir
.endif

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.4:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>0.8:../../devel/py-simplegeneric
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets

PYTHON_VERSIONED_DEPENDENCIES+=	pygments setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/iptest bin/iptest${PYVERSSUFFIX} && \
	${MV} bin/ipython bin/ipython${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"

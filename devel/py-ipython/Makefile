# $NetBSD: Makefile,v 1.21 2017/06/24 08:07:14 adam Exp $

DISTNAME=	ipython-5.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
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
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.4:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>0.8:../../devel/py-simplegeneric
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets

USE_LANGUAGES=	# none

REPLACE_PYTHON=	*/*/*.py */*/*/*.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/iptest ${DESTDIR}${PREFIX}/bin/iptest${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/ipython ${DESTDIR}${PREFIX}/bin/ipython${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ipython.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ipython${PYVERSSUFFIX}.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

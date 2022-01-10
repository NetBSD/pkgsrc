# $NetBSD: Makefile,v 1.13 2022/01/10 07:53:41 wiz Exp $

DISTNAME=	ipython-5.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

# 2.7 only
DEPENDS+=	${PYPKGPREFIX}-backports.shutil_get_terminal_size-[0-9]*:../../devel/py-backports.shutil_get_terminal_size
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-scandir-[0-9]*:../../devel/py-scandir

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.4:../../devel/py-prompt_toolkit1
DEPENDS+=	${PYPKGPREFIX}-pygments<2.6:../../textproc/py-pygments25
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools44
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>0.8:../../devel/py-simplegeneric
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets4
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == Darwin
DEPENDS+=	${PYPKGPREFIX}-appnope-[0-9]*:../../sysutils/py-appnope
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/iptest bin/iptest-${PYVERSSUFFIX} && \
	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

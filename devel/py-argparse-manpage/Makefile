# $NetBSD: Makefile,v 1.5 2024/06/07 11:09:24 adam Exp $

DISTNAME=	argparse-manpage-4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argparse-manpage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/praiskup/argparse-manpage
COMMENT=	Build manual page from python's ArgumentParser object
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} argparse-manpage argparse-manpage-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX} && \
	${MV} share/man/man1/argparse-manpage.1 ${PKGMANDIR}/man1/argparse-manpage-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

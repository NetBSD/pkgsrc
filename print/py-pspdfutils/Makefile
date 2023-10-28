# $NetBSD: Makefile,v 1.12 2023/10/28 19:57:14 wiz Exp $

DISTNAME=	pspdfutils-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pspdfutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils
COMMENT=	Manipulate PDF and PostScript documents
LICENSE=	gnu-gpl-v3

CONFLICTS+=	psutils<3

TOOL_DEPENDS+=	${PYPKGPREFIX}-argparse-manpage-[0-9]*:../../devel/py-argparse-manpage
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-puremagic-[0-9]*:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-pdf>=3.1.0:../../textproc/py-pdf
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datafiles>=0:../../devel/py-test-datafiles
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

INSTALLATION_DIRS+=	${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${PKGMANDIR} != "share/man"
	cd ${DESTDIR}${PREFIX}/share/man && ${MV} * ${DESTDIR}${PREFIX}/${PKGMANDIR}
.endif

# still needs 'make install'
# most tests don't pass, should be investigated
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../print/libpaper/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

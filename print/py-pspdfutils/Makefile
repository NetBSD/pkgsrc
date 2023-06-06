# $NetBSD: Makefile,v 1.3 2023/06/06 14:01:23 wiz Exp $

DISTNAME=	pspdfutils-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pspdfutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils
COMMENT=	Manipulate PDF and PostScript documents
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-argparse-manpage-[0-9]*:../../devel/py-argparse-manpage
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-puremagic-[0-9]*:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-pdf>=3.8.0:../../textproc/py-pdf
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datafiles>=0:../../devel/py-test-datafiles
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

INSTALLATION_DIRS+=	${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
.endif

CONFLICTS+=	psutils<3

post-install:
	cd ${DESTDIR}${PREFIX}/share/man && ${MV} * ${DESTDIR}${PREFIX}/${PKGMANDIR}

# still needs 'make install'
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../print/libpaper/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

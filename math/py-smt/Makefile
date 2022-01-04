#	$NetBSD: Makefile,v 1.2 2022/01/04 20:54:17 wiz Exp $

VERSION=	0.9.0
DISTNAME=	PySMT-${VERSION}
PKGNAME=	${PYPKGPREFIX}-smt-${VERSION}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=pysmt/}
GITHUB_PROJECT=	pysmt
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pysmt.org/
COMMENT=	Library for SMT formula manipulation and solving
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-z3>=0:../../math/py-z3

SUBST_CLASSES+=		python3
SUBST_STAGE.python3=	pre-test
SUBST_MESSAGE.python3=	Fixing python3 interpreter
SUBST_SED.python3+=	-e 's,python3 ,${PYTHONBIN} ,'
SUBST_FILES.python3+=	run_tests.sh

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	${SH} run_tests.sh

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

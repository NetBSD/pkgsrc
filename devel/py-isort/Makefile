# $NetBSD: Makefile,v 1.35 2026/03/02 12:47:36 wiz Exp $

DISTNAME=	isort-8.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/isort
COMMENT=	Python utility/library to sort imports
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.10.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith>=0.1.3:../../devel/py-hypothesmith
TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.7:../../devel/py-lama
TEST_DEPENDS+=	${PYPKGPREFIX}-libcst>=0.3.18:../../lang/py-libcst
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 8.0.1
# 5 failed, 553 passed, 1 skipped, 1 xpassed, 2 errors

post-install:
.for bin in isort isort-identify-imports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

pre-test:
	${RM} -f ${BUILDLINK_DIR}/bin/isort
	${LN} -s ${PREFIX}/bin/isort-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/isort

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

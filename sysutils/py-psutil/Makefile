# $NetBSD: Makefile,v 1.52 2024/01/20 08:05:41 adam Exp $

DISTNAME=	psutil-5.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=43:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SYSTEM=osx
.elif ${OPSYS:M*BSD}
PLIST_SUBST+=	SYSTEM=bsd
.else
PLIST_SUBST+=	SYSTEM=${OPSYS:tl}
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} psutil/tests/runner.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

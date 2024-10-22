# $NetBSD: Makefile,v 1.54 2024/10/22 08:14:48 wiz Exp $

DISTNAME=	psutil-6.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=43:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SYSTEM=osx
.elif ${OPSYS:M*BSD}
PLIST_SUBST+=	SYSTEM=bsd
.else
PLIST_SUBST+=	SYSTEM=${OPSYS:tl}
.endif

# https://github.com/giampaolo/psutil/issues/2465
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m psutil.tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

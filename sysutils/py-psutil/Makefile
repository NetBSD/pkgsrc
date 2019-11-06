# $NetBSD: Makefile,v 1.34 2019/11/06 15:48:23 adam Exp $

DISTNAME=	psutil-5.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
TEST_DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SYSTEM=osx
.elif !empty(OPSYS:M*BSD)
PLIST_SUBST+=	SYSTEM=bsd
.else
PLIST_SUBST+=	SYSTEM=${OPSYS:tl}
.endif

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} psutil/tests/__main__.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

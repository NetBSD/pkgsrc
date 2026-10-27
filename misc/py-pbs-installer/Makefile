# $NetBSD: Makefile,v 1.25 2026/10/27 12:13:01 adam Exp $

DISTNAME=	pbs_installer-2026.10.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbs-installer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/pbs-installer
COMMENT=	Installer for Python Build Standalone
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
# download
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.14.0:../../www/py-httpx2

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pbs-install

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2026/03/30 09:28:08 adam Exp $

DISTNAME=	pbs_installer-2026.3.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbs-installer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/pbs-installer
COMMENT=	Installer for Python Build Standalone
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
# download
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
# install
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.21.0:../../archivers/py-zstandard

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pbs-install pbs-install-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

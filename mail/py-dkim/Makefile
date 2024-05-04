# $NetBSD: Makefile,v 1.5 2024/05/04 23:52:06 jym Exp $

DISTNAME=	dkimpy-1.1.6
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dkimpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/dkimpy/
COMMENT=	DKIM, ARC, and TLSRPT email signing and verification
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiodns-[0-9]*:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-authres>=1.2.0:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-dns>=2.0.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.py
SUBST_VARS.paths=	PKGMANDIR

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

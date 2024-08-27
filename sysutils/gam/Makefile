# $NetBSD: Makefile,v 1.6 2024/08/27 16:04:44 sborrill Exp $

DISTNAME=	gam-6.58
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=GAM-team/}
GITHUB_PROJECT=	GAM
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GAM-team/GAM
COMMENT=	Command line tool for Google Workspace admins
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=2.0:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.11.2:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2-[0-9]*:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0.4.1:../../security/py-google-auth-oauthlib
DEPENDS+=	${PYPKGPREFIX}-pathvalidate-[0-9]*:../../devel/py-pathvalidate
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.2:../../security/py-passlib

EGG_NAME=	GAM_for_Google_Workspace-${PKGVERSION_NOREV}

NO_BUILD=	yes
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
REPLACE_PYTHON=	gam.py
WRKSRC=		${WRKDIR}/GAM-${PKGVERSION_NOREV}/src

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	gam/var.py
SUBST_VARS.paths=	LOCALBASE

INSTALLATION_DIRS=	bin ${PYSITELIB}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.10 2024/12/13 13:33:44 sborrill Exp $

DISTNAME=	gam-7.02.00
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=GAM-team/}
GITHUB_PROJECT=	GAM
GITHUB_TAG=	v${PKGVERSION_NOREV}
# The version internally sometimes has leading zeros removed
VERSION_TRIM=	${PKGVERSION_NOREV:C/\.0([0-9])/.\1/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GAM-team/GAM
COMMENT=	Command line tool for Google Workspace admins
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1.0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=2.0:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.11.2:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2-[0-9]*:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0.4.1:../../security/py-google-auth-oauthlib
DEPENDS+=	${PYPKGPREFIX}-pathvalidate-[0-9]*:../../devel/py-pathvalidate
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.2:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	INFODIR=GAM_for_Google_Workspace-${VERSION_TRIM}.dist-info

REPLACE_PYTHON=	gam.py
WRKSRC=		${WRKDIR}/GAM-${PKGVERSION_NOREV}/src

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	setup.cfg
SUBST_VARS.version=	PKGVERSION_NOREV

INSTALLATION_DIRS=	bin ${PYSITELIB}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

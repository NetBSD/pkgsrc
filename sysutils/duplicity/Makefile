# $NetBSD: Makefile,v 1.67 2024/05/24 15:08:38 triaxx Exp $

DISTNAME=	duplicity-2.2.4
PKGREVISION=	1
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/duplicity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://duplicity.us/
COMMENT=	Remote encrypting incremental backup utility
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=44.1.1:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=5.0.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	lftp-[0-9]*:../../net/lftp
DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-botocore-[0-9]*:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-dropbox-[0-9]*:../../net/py-dropbox
DEPENDS+=	${PYPKGPREFIX}-fasteners-[0-9]*:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client-[0-9]*:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib-[0-9]*:../../security/py-google-auth-oauthlib
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-swiftclient-[0-9]*:../../www/py-swiftclient
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

GPG=	${PREFIX}/bin/gpg2
LFTP=	${PREFIX}/bin/lftp

REPLACE_PYTHON+=	bin/duplicity
REPLACE_PYTHON+=	bin/rdiffdir

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing hard coded directories
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.fix-paths+=		-e 's,share/locale,${PKGLOCALEDIR}/locale,'

SUBST_CLASSES+=			fix-bins
SUBST_STAGE.fix-bins=		pre-configure
SUBST_MESSAGE.fix-bins=		Fixing relative binary paths
SUBST_FILES.fix-bins=		duplicity/backends/lftpbackend.py duplicity/gpginterface.py
SUBST_VARS.fix-bins=		GPG LFTP

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

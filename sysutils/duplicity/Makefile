# $NetBSD: Makefile,v 1.57 2022/06/30 11:18:50 nia Exp $

DISTNAME=	duplicity-0.8.20
PKGREVISION=	3
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/duplicity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/duplicity/
COMMENT=	Remote encrypting incremental backup utility
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-fasteners-[0-9]*:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

GPGPATH=	${PREFIX}/bin/gpg2
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	lftp-[0-9]*:../../net/lftp
DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-dropbox-[0-9]*:../../net/py-dropbox
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-swiftclient-[0-9]*:../../www/py-swiftclient
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

REPLACE_PYTHON+=	bin/duplicity
REPLACE_PYTHON+=	bin/rdiffdir

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing hard coded dirs
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.fix-paths+=		-e 's,share/locale,${PKGLOCALEDIR}/locale,'

SUBST_CLASSES+=			gpgpath
SUBST_STAGE.gpgpath=		pre-configure
SUBST_FILES.gpgpath=		duplicity/gpginterface.py
SUBST_VARS.gpgpath=		GPGPATH

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2022/10/19 13:56:33 nia Exp $

DISTNAME=	requests-kerberos-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-kerberos
COMMENT=	Kerberos authentication handler for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-kerberos>=1.1.8nb1:../../security/py-kerberos
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

SUBST_CLASSES+=		requires
SUBST_STAGE.requires=	pre-configure
SUBST_FILES.requires=	setup.py
SUBST_SED.requires=	-e 's/pykerberos/kerberos/'

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"

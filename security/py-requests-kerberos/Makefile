# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:44 wiz Exp $

DISTNAME=	requests-kerberos-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-kerberos
COMMENT=	Kerberos authentication handler for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-kerberos>=1.1.8nb1:../../security/py-kerberos
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

SUBST_CLASSES+=		requires
SUBST_STAGE.requires=	pre-configure
SUBST_FILES.requires=	setup.py
SUBST_SED.requires=	-e 's/pykerberos/kerberos/'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

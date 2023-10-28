# $NetBSD: Makefile,v 1.2 2023/10/28 19:57:15 wiz Exp $

DISTNAME=	solo1-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/solo1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/solokeys/solo1-cli/
COMMENT=	Tool for managing SoloKeys Solo 1
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit>=0:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-click>=7.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-fido2>=0.9.1:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-intelhex>=0:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-serial>=0:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-usb>=0:../../devel/py-usb

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-flit

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/solo && ${RM} -f *.orig */*.orig

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

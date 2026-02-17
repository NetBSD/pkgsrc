# $NetBSD: Makefile,v 1.2 2026/02/17 09:30:09 adam Exp $

DISTNAME=	pyhanko-0.33.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyhanko/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MatthiasValvekens/pyHanko
COMMENT=	Tools for stamping and signing PDF files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.8.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=1.5.1:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=4.3:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-hanko-certvalidator>=0.29.0:../../security/py-hanko-certvalidator
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-cryptography>=43.0.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.4.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

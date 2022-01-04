# $NetBSD: Makefile,v 1.36 2022/01/04 20:54:32 wiz Exp $

DISTNAME=	SOAPpy-0.12.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SOAPpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiorky/SOAPpy
COMMENT=	SOAP Services for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-wstools-[0-9]*:../../www/py-wstools

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

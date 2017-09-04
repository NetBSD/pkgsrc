# $NetBSD: Makefile,v 1.6 2017/09/04 18:00:58 wiz Exp $

DISTNAME=	PySimpleSOAP-1.16
PKGNAME=	${DISTNAME:tl:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysimplesoap/}

MAINTAINER=	rodent@NetBSD.org
#HOMEPAGE=	https://pysimplesoap.googlecode.com/files/
COMMENT=	Python Simple SOAP Library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 1.16

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2016/08/18 21:05:35 richard Exp $

DISTNAME=	PySimpleSOAP-1.16
PKGNAME=	${DISTNAME:tl:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysimplesoap/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pysimplesoap.googlecode.com/files/
COMMENT=	Python Simple SOAP Library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

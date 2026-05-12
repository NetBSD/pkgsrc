# $NetBSD: Makefile,v 1.26 2026/05/12 06:24:16 adam Exp $

DISTNAME=	pysmb-1.2.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://miketeo.net/blog/projects/pysmb
COMMENT=	Experimental SMB/CIFS library written in Python
LICENSE=	zlib

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.20 2023/03/09 05:26:07 adam Exp $

DISTNAME=	pysmb-1.2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmb/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://miketeo.net/wp/index.php/projects/pysmb
COMMENT=	Experimental SMB/CIFS library written in Python
LICENSE=	zlib

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-tqdm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

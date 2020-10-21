# $NetBSD: Makefile,v 1.13 2020/10/21 12:08:16 adam Exp $

DISTNAME=	pysmb-1.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysmb/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://miketeo.net/wp/index.php/projects/pysmb
COMMENT=	Experimental SMB/CIFS library written in Python
LICENSE=	zlib

DEPENDS+=	${PYPKGPREFIX}-asn1>=0:../../security/py-asn1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

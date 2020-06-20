# $NetBSD: Makefile,v 1.10 2020/06/20 16:16:13 adam Exp $

DISTNAME=	pysmb-1.2.1
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

# $NetBSD: Makefile,v 1.3 2004/08/07 14:31:57 minskim Exp $
#

DISTNAME=	cjkcodecs-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://download.berlios.de/cjkpython/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cjkpython.berlios.de/
COMMENT=	Python Unicode codecs for Chinese, Japanese, and Korean encodings

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3=	yes

post-install:
	@strip ${PREFIX}/${PYSITELIB}/cjkcodecs/*.so

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2004/02/07 21:28:35 minskim Exp $
#

DISTNAME=	cjkcodecs-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
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

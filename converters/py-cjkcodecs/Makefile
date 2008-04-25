# $NetBSD: Makefile,v 1.9 2008/04/25 20:39:06 joerg Exp $
#

DISTNAME=	cjkcodecs-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	http://download.berlios.de/cjkpython/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cjkpython.berlios.de/
COMMENT=	Python Unicode codecs for Chinese, Japanese, and Korean encodings

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYTHON_VERSIONS_ACCEPTED= 23 21

post-install:
	@strip ${PREFIX}/${PYSITELIB}/cjkcodecs/*.so

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

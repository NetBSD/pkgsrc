# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:29 joerg Exp $
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

post-install:
	@strip ${PREFIX}/${PYSITELIB}/cjkcodecs/*.so

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:17 joerg Exp $
#

DISTNAME=	cjkcodecs-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	http://download.berlios.de/cjkpython/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cjkpython.berlios.de/
COMMENT=	Python Unicode codecs for Chinese, Japanese, and Korean encodings

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYTHON_VERSIONS_ACCEPTED= 23 21

post-install:
	@strip ${PREFIX}/${PYSITELIB}/cjkcodecs/*.so

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

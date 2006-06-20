# $NetBSD: Makefile,v 1.26 2006/06/20 23:32:36 minskim Exp $

DISTNAME=	Imaging-1.1.5
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.5
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DIST_SUBDIR=    python
PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYINC}/PIL
	(cd ${WRKSRC}/libImaging; ${INSTALL_DATA} \
		ImPlatform.h Imaging.h \
		${PREFIX}/${PYINC}/PIL )

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

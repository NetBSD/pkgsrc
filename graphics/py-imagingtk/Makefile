# $NetBSD: Makefile,v 1.17 2005/12/05 20:50:22 rillig Exp $
#

DISTNAME=	Imaging-1.1.5
PKGNAME=	${PYPKGPREFIX}-imagingtk-1.1.5
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

DIST_SUBDIR=    python
PYDISTUTILSPKG=	yes
BUILDLINK_DEPENDS.python20+=	python20>=2.0.1nb4
PY_PATCHPLIST=	yes

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PYPKGPREFIX}-imaging
	(cd ${WRKSRC}/Scripts; \
	${INSTALL_DATA} enhancer.py painter.py player.py \
	thresholder.py viewer.py \
	${PREFIX}/share/examples/${PYPKGPREFIX}-imaging )

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

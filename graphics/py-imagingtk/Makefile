# $NetBSD: Makefile,v 1.24 2009/12/11 21:40:30 drochner Exp $
#

DISTNAME=	Imaging-1.1.7
PKGNAME=	${PYPKGPREFIX}-imagingtk-1.1.7
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

DIST_SUBDIR=	python
PYDISTUTILSPKG=	yes
BUILDLINK_API_DEPENDS.python20+=	python20>=2.0.1nb4
PY_PATCHPLIST=	yes

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PKG_DESTDIR_SUPPORT= user-destdir

post-install:
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-imaging
	(cd ${WRKSRC}/Scripts; \
	${INSTALL_DATA} enhancer.py painter.py player.py \
	thresholder.py viewer.py \
	${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-imaging )

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

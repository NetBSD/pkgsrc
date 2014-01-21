# $NetBSD: Makefile,v 1.34 2014/01/21 10:15:09 wiz Exp $

DISTNAME=	Imaging-1.1.7
PKGNAME=	${PYPKGPREFIX}-imagingtk-1.1.7
PKGREVISION=	7
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

DIST_SUBDIR=	python
EGG_NAME=	${DISTNAME:S/Imaging/PIL/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-imaging

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

post-install:
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-imaging
	(cd ${WRKSRC}/Scripts; \
	${INSTALL_DATA} enhancer.py painter.py player.py \
	thresholder.py viewer.py \
	${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-imaging )

.include "../../lang/python/distutils.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

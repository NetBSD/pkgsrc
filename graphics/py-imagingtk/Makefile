# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:57 tv Exp $
#

DISTNAME=	Imaging-1.1.4
PKGNAME=	${PYPKGPREFIX}-imagingtk-1.1.4
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

DIST_SUBDIR=    python
PYDISTUTILSPKG=	yes
BUILDLINK_DEPENDS.python20=	python20>=2.0.1nb4
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_X11=	yes

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

do-configure:
	(cd ${WRKSRC}/libImaging && ${SETENV} ${CONFIGURE_ENV} ./configure \
	 ${CONFIGURE_ARGS} && ${SETENV} ${MAKE_ENV} ${MAKE})
	${SED} "s|@JPEGDIR@|${BUILDLINK_PREFIX.jpeg}|g" <${WRKSRC}/setup.py \
	 >${WRKSRC}/setup.py.tmp && ${MV} -f ${WRKSRC}/setup.py.tmp \
	 ${WRKSRC}/setup.py

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

# $NetBSD: Makefile,v 1.8 2012/10/03 11:43:48 asau Exp $
#

DISTNAME=	zim-0.56
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	http://zim-wiki.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://zim-wiki.org/
COMMENT=	Zim brings the concept of a wiki to your desktop
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

REPLACE_PYTHON=	${WRKSRC}/zim.py
PYDISTUTILSPKG=	YES

DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

SUBST_CLASSES+=		data-path
SUBST_STAGE.data-path=	pre-configure
SUBST_FILES.data-path=	zim/config.py
SUBST_SED.data-path=	-e 's,/usr/local/share/,${PREFIX}/share/,'

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	zim/_lib/xdot.py
SUBST_FILES.fix-python+=	zim/_version.py
SUBST_FILES.fix-python+=	zim/inc/xdot.py
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

SUBST_CLASSES+=			man-path
SUBST_STAGE.man-path=		pre-configure
SUBST_FILES.man-path+=		setup.py
SUBST_SED.man-path=		-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == "py25"
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

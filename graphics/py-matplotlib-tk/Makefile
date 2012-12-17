# $NetBSD: Makefile,v 1.14 2012/12/17 11:52:43 drochner Exp $
#

DISTNAME=		matplotlib-1.2.0
PKGNAME=		${PYPKGPREFIX}-matplotlib-tk-1.2.0
CATEGORIES=		graphics python
MASTER_SITES=		https://github.com/downloads/matplotlib/matplotlib/
FETCH_USING=		curl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Tk frontend for matplotlib

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

post-patch:
	( echo "[directories]"; \
	echo "basedirlist=/usr"; \
	echo "[provide_packages]"; \
	echo "pytz = False"; \
	echo "dateutil = False"; \
	echo "[gui_support]"; \
	echo "gtk = False"; \
	echo "gtkagg = False"; \
	echo "tkagg = True"; \
	echo "wxagg = False"; \
	echo "macosx = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

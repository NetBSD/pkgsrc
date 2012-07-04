# $NetBSD: Makefile,v 1.11 2012/07/04 20:41:29 drochner Exp $
#

DISTNAME=		matplotlib-1.1.1
PKGNAME=		${PYPKGPREFIX}-matplotlib-tk-1.1.1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Tk frontend for matplotlib

PKG_DESTDIR_SUPPORT=	user-destdir

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

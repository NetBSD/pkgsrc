# $NetBSD: Makefile,v 1.24 2011/11/01 06:01:44 sbd Exp $
#

DISTNAME=		matplotlib-1.0.1
PKGNAME=		${PYPKGPREFIX}-matplotlib-gtk-1.0.1
PKGREVISION=		2
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		GTK frontend for matplotlib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_ACCEPTED=	27 26 25

post-patch:
	( echo "[directories]"; \
	echo "basedirlist=/usr"; \
	echo "[provide_packages]"; \
	echo "pytz = False"; \
	echo "dateutil = False"; \
	echo "[gui_support]"; \
	echo "gtk = True"; \
	echo "gtkagg = True"; \
	echo "tkagg = False"; \
	echo "wxagg = False"; \
	echo "macosx = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

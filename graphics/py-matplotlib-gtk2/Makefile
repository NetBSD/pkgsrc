# $NetBSD: Makefile,v 1.12 2009/02/11 14:23:32 joerg Exp $
#

DISTNAME=		matplotlib-0.98.0
PKGNAME=		${PYPKGPREFIX}-matplotlib-gtk-0.98.0
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

PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

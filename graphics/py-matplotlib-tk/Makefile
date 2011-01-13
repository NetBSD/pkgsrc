# $NetBSD: Makefile,v 1.7 2011/01/13 13:38:17 wiz Exp $
#

DISTNAME=		matplotlib-0.99.1.2
PKGNAME=		${PYPKGPREFIX}-matplotlib-tk-0.99.1.2
PKGREVISION=		2
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Tk frontend for matplotlib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/matplotlib-0.99.1.1
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++


.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

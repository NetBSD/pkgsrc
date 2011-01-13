# $NetBSD: Makefile,v 1.20 2011/01/13 13:38:17 wiz Exp $
#

DISTNAME=		matplotlib-0.99.1.2
PKGNAME=		${PYPKGPREFIX}-matplotlib-gtk-0.99.1.2
PKGREVISION=		4
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		GTK frontend for matplotlib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/matplotlib-0.99.1.1
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_ACCEPTED=	26 25

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

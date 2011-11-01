# $NetBSD: Makefile,v 1.29 2011/11/01 06:01:44 sbd Exp $
#

DISTNAME=		matplotlib-1.0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

DEPENDS+=		${PYPKGPREFIX}-pytz>=2008b:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-dateutil>=1.2:../../time/py-dateutil

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

post-patch:
	( echo "[directories]"; \
	echo "basedirlist=/usr"; \
	echo "[gui_support]"; \
	echo "gtk = False"; \
	echo "gtkagg = False"; \
	echo "tkagg = False"; \
	echo "wxagg = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

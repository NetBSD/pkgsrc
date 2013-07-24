# $NetBSD: Makefile,v 1.21 2013/07/24 11:13:56 drochner Exp $

DISTNAME=		matplotlib-1.2.1
PKGNAME=		${PYPKGPREFIX}-matplotlib-tk-1.2.1
CATEGORIES=		graphics python
MASTER_SITES=		https://github.com/downloads/matplotlib/matplotlib/
FETCH_USING=		curl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Tk frontend for matplotlib

DEPENDS+=		${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

post-patch:
	( ${ECHO} "[directories]"; \
	${ECHO} "basedirlist=/usr"; \
	${ECHO} "[provide_packages]"; \
	${ECHO} "pytz = False"; \
	${ECHO} "dateutil = False"; \
	${ECHO} "[gui_support]"; \
	${ECHO} "gtk = False"; \
	${ECHO} "gtkagg = False"; \
	${ECHO} "tkagg = True"; \
	${ECHO} "wxagg = False"; \
	${ECHO} "macosx = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/extension.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

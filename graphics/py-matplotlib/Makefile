# $NetBSD: Makefile,v 1.42 2014/02/06 01:53:16 obache Exp $

DISTNAME=		matplotlib-1.3.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.org/
COMMENT=		Matlab-style plotting package for Python

DEPENDS+=		${PYPKGPREFIX}-pytz>=2008b:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-pyparsing>=1.5.6:../../devel/py-pyparsing

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes

REPLACE_PYTHON=		lib/matplotlib/dates.py
REPLACE_PYTHON+=	lib/matplotlib/sankey.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/art3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/axes3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/axis3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/proj3d.py

post-patch:
	( ${ECHO} "[directories]"; \
	${ECHO} "basedirlist=/usr"; \
	${ECHO} "[gui_support]"; \
	${ECHO} "gtk = False"; \
	${ECHO} "gtkagg = False"; \
	${ECHO} "tkagg = False"; \
	${ECHO} "wxagg = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

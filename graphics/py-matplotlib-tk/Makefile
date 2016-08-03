# $NetBSD: Makefile,v 1.28 2016/08/03 23:22:14 kamil Exp $

VERSION=		1.5.2
DISTNAME=		matplotlib-${VERSION}
PKGNAME=		${PYPKGPREFIX}-matplotlib-tk-${VERSION}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_GITHUB:=matplotlib/}
GITHUB_PROJECT=		matplotlib
GITHUB_TAG=		v${PKGVERSION_NOREV}

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

post-install:
	${RM} -r ${DESTDIR}/${PREFIX}/${PYSITELIB}/${EGG_INFODIR}

# It needs:
# devel/py-cycler
# devel/py-nose
# devel/py-mock
do-test:
	${ECHO} "backend      : TkAgg" > ${WRKSRC}/matplotlibrc
	${RUN} cd ${WRKSRC} && MPLCONFIGDIR=$PWD \
	MATPLOTLIBDATA=${WRKSRC}/lib/matplotlib/mpl-data \
	PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
	${PYTHONBIN} -c "import matplotlib; matplotlib.test()"

.include "../../lang/python/egg.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

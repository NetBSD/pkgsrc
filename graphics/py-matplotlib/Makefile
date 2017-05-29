# $NetBSD: Makefile,v 1.47 2017/05/29 20:59:21 adam Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Matlab-style plotting package for Python

DEPENDS+=	${PYPKGPREFIX}-cycler-[0-9]*:../../graphics/py-cycler
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>=2008b:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.6:../../devel/py-pyparsing
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
.else
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo3
.endif

MPL_PACKAGES=	mpl_packages

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
	${ECHO} "tkagg = False"; \
	${ECHO} "wxagg = False" ) > ${WRKSRC}/setup.cfg

do-test:
	${ECHO} "backend      : GTKAgg" > ${WRKSRC}/matplotlibrc
	${RUN} cd ${WRKSRC} && MPLCONFIGDIR=${PWD} \
	MATPLOTLIBDATA=${WRKSRC}/lib/matplotlib/mpl-data \
	PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
	${PYTHONBIN} -c "import matplotlib; matplotlib.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

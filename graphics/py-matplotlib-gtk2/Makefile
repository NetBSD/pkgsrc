# $NetBSD: Makefile,v 1.68 2018/11/12 03:52:17 ryoon Exp $

PKGREVISION= 3
.include "../../graphics/py-matplotlib/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/-gtk-/}
COMMENT=	GTK frontend for matplotlib

MPL_PACKAGES=	[setupext.Numpy(),setupext.LibAgg(),setupext.BackendGtkAgg(),setupext.BackendGtk()]

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

post-patch:
	( ${ECHO} "[directories]"; \
	${ECHO} "basedirlist=/usr"; \
	${ECHO} "[provide_packages]"; \
	${ECHO} "pytz = False"; \
	${ECHO} "dateutil = False"; \
	${ECHO} "[gui_support]"; \
	${ECHO} "gtk = True"; \
	${ECHO} "tkagg = False"; \
	${ECHO} "wxagg = False"; \
	${ECHO} "macosx = False" ) > ${WRKSRC}/setup.cfg

post-install:
	${RM} -r ${DESTDIR}/${PREFIX}/${PYSITELIB}/${EGG_INFODIR}

do-test:
	${ECHO} "backend      : GTKAgg" > ${WRKSRC}/matplotlibrc
	${RUN} cd ${WRKSRC} && MPLCONFIGDIR=${PWD} \
	MATPLOTLIBDATA=${WRKSRC}/lib/matplotlib/mpl-data \
	PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
	${PYTHONBIN} -c "import matplotlib; matplotlib.test()"

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

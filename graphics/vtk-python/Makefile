# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:58 tv Exp $
#

PKGNAME=	vtk-python-${VTKDIST_VERSION}
PKGREVISION=	1

COMMENT=	Python wrapper libraries for vtk; see vtk package for details

VTK_CMAKE_OPT=  -DPYTHON_INCLUDE_PATH:STRING=${PREFIX}/${PYINC} \
		-DPYTHON_LIBRARY:STRING=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so \
		-DVTK_WRAP_PYTHON:BOOL=ON

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23pth
PYSETUPSUBDIR=			Wrapping/Python

VTK_PY_LIBS=	bin/libvtkCommonPython.so \
		bin/libvtkFilteringPython.so \
		bin/libvtkImagingPython.so \
		bin/libvtkGraphicsPython.so \
		bin/libvtkIOPython.so \
		bin/libvtkRenderingPython.so \
		bin/libvtkRenderingPythonTkWidgets.so \
		bin/libvtkHybridPython.so

ALL_TARGET=	default_target_Wrapping_Python

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

pre-install:
	for lib in ${VTK_PY_LIBS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$lib ${VTK_LIBDIR}; \
	done

# XXX this doesn't get linked with correct RPATH, and is unnecessary anyway
post-install:
	${RM} -f ${PREFIX}/bin/vtkpython
	${LN} -s ${PYTHONBIN} ${PREFIX}/bin/vtkpython

DEPENDS=	vtk>=${VTK_VERSION}:../../graphics/vtk

.include "../../graphics/vtk/Makefile.vtkdist"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

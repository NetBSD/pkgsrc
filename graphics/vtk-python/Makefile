# $NetBSD: Makefile,v 1.14 2007/06/18 19:15:44 joerg Exp $
#

PKGNAME=	vtk-python-${VTKDIST_VERSION}
PKGREVISION=	3

COMMENT=	Python wrapper libraries for vtk; see vtk package for details

VTK_CMAKE_OPT=	-DPYTHON_INCLUDE_PATH:STRING=${PREFIX}/${PYINC} \
		-DPYTHON_LIBRARY:STRING=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so \
		-DVTK_WRAP_PYTHON:BOOL=ON \
		-DOPENGL_INCLUDE_DIR=${BUILDLINK_PREFIX.MesaLib:Q} \
		-DCMAKE_BACKWARDS_COMPATIBILITY=2.2

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23
PYSETUPSUBDIR=			Wrapping/Python

VTK_PY_LIBS=	bin/libvtkCommonPython.so \
		bin/libvtkFilteringPython.so \
		bin/libvtkImagingPython.so \
		bin/libvtkGraphicsPython.so \
		bin/libvtkIOPython.so \
		bin/libvtkRenderingPython.so \
		bin/libvtkRenderingPythonTkWidgets.so \
		bin/libvtkHybridPython.so

BUILD_TARGET=	vtkpython/fast \
		vtkWrapPython/fast \
		vtkCommonPython/fast \
		vtkFilteringPython/fast \
		vtkImagingPython/fast \
		vtkGraphicsPython/fast \
		vtkIOPython/fast \
		vtkRenderingPython/fast \
		vtkRenderingPythonTkWidgets/fast \
		vtkHybridPython/fast

post-configure:
	${INSTALL_LIB} ${PREFIX}/lib/vtk/*.so ${WRKSRC}/bin

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${BUILD_TARGET}

pre-install:
	for lib in ${VTK_PY_LIBS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$lib ${VTK_LIBDIR}; \
	done

DEPENDS+=	vtk>=${VTK_VERSION}:../../graphics/vtk

.include "../../graphics/vtk/Makefile.vtkdist"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

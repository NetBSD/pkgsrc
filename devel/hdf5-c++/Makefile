# $NetBSD: Makefile,v 1.1.1.1 2011/10/07 10:42:18 alnsn Exp $

PKGNAME=	hdf5-c++-${HDF5_VER}
COMMENT=	Hierarchical Data Format (new generation) - C++ wrappers

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--enable-cxx

INSTALLATION_DIRS=	bin lib include
INSTALLATION_DIRS+=	share/examples/hdf5/c++
INSTALLATION_DIRS+=	share/examples/hdf5/hl/c++

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/c++/src/h5c++ ${DESTDIR}/${PREFIX}/bin/
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/c++/src/libhdf5_cpp.la ${DESTDIR}/${PREFIX}/lib/
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/hl/c++/src/libhdf5_hl_cpp.la ${DESTDIR}/${PREFIX}/lib/
	${INSTALL_DATA} \
	    ${WRKSRC}/hl/c++/src/H5PacketTable.h ${DESTDIR}/${PREFIX}/include/
.for f in H5AbstractDs.h H5ArrayType.h H5AtomType.h H5Attribute.h H5Classes.h \
          H5CommonFG.h H5CompType.h H5Cpp.h H5CppDoc.h H5DataSet.h \
	  H5DataSpace.h H5DataType.h H5DcreatProp.h H5DxferProp.h H5EnumType.h \
	  H5Exception.h H5FaccProp.h H5FcreatProp.h H5File.h H5FloatType.h \
	  H5Group.h H5IdComponent.h H5Include.h H5IntType.h H5Library.h \
	  H5Object.h H5PredType.h H5PropList.h H5StrType.h H5VarLenType.h
	${INSTALL_DATA} ${WRKSRC}/c++/src/$f ${DESTDIR}/${PREFIX}/include/
.endfor
.for f in chunks.cpp compound.cpp create.cpp extend_ds.cpp \
	  h5group.cpp readdata.cpp run-c++-ex.sh writedata.cpp
	${INSTALL_DATA} ${WRKSRC}/c++/examples/$f \
	    ${DESTDIR}/${PREFIX}/share/examples/hdf5/c++/
.endfor
.for f in ptExampleFL.cpp ptExampleVL.cpp run-hlc++-ex.sh
	${INSTALL_DATA} ${WRKSRC}/hl/c++/examples/$f \
	    ${DESTDIR}/${PREFIX}/share/examples/hdf5/hl/c++/
.endfor

.include "../../devel/hdf5/Makefile.common"

.include "../../devel/hdf5/buildlink3.mk"

# Since the package is build from source code shared with hdf5,
# same options should be passed:
.if !empty(PKG_BUILD_OPTIONS.hdf5:Mszip)
CONFIGURE_ARGS+=	--with-szlib
.endif

.if !empty(PKG_BUILD_OPTIONS.hdf5:Mthreads)
CONFIGURE_ARGS+=	--enable-threadsafe
.endif

.include "../../mk/bsd.pkg.mk"

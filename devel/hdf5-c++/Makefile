# $NetBSD: Makefile,v 1.9 2022/07/22 14:50:33 thor Exp $

PKGNAME=	${DISTNAME:S/-/-c++-/}
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
	${INSTALL_DATA} ${WRKSRC}/hl/c++/src/*.h ${DESTDIR}/${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/c++/src/*.h ${DESTDIR}/${PREFIX}/include/
.for f in chunks.cpp compound.cpp create.cpp extend_ds.cpp \
	  h5group.cpp readdata.cpp run-c++-ex.sh writedata.cpp
	${INSTALL_DATA} ${WRKSRC}/c++/examples/${f} \
	    ${DESTDIR}/${PREFIX}/share/examples/hdf5/c++/
.endfor
.for f in ptExampleFL.cpp run-hlc++-ex.sh
	${INSTALL_DATA} ${WRKSRC}/hl/c++/examples/${f} \
	    ${DESTDIR}/${PREFIX}/share/examples/hdf5/hl/c++/
.endfor

.include "../../devel/hdf5/Makefile.common"
.include "../../devel/hdf5/buildlink3.mk"
# Since the package is build from source code shared with hdf5,
# same options should be passed:
.include "../../devel/hdf5/options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
PKG_FAIL_REASON=	"Threadsafe HDF5 with C++ interface is unsupported."
.endif

.include "../../mk/bsd.pkg.mk"

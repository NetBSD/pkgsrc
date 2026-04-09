# $NetBSD: options.mk,v 1.15 2026/04/09 07:11:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hdf5
PKG_SUPPORTED_OPTIONS=	mpi szip threads hdf5-unsafe-threads
PKG_SUGGESTED_OPTIONS=	szip

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mpi
.if !empty(PKG_OPTIONS:Mmpi)
PLIST.mpi=	yes
CMAKE_CONFIGURE_ARGS+=	-DHDF5_ENABLE_PARALLEL=ON
.include "../../parallel/openmpi/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DHDF5_ENABLE_PARALLEL=OFF
.endif

.if !empty(PKG_OPTIONS:Mszip)
CMAKE_CONFIGURE_ARGS+=	-DHDF5_ENABLE_SZIP_SUPPORT=ON
.include "../../archivers/libaec/buildlink3.mk"
.endif

# Threadsafe API is incompatible with high-level and C++ APIs.
PLIST_VARS+=	hl
.if !empty(PKG_OPTIONS:Mthreads)
CMAKE_CONFIGURE_ARGS+=	-DHDF5_BUILD_HL_LIB=OFF # not compatible with threadsafe
CMAKE_CONFIGURE_ARGS+=	-DHDF5_ENABLE_THREADSAFE=ON
#SUBST_FILES.unwrap+=	${DESTDIR}${PREFIX}/bin/h5hlcc
.include "../../mk/pthread.buildlink3.mk"
.else
PLIST.hl=	yes
.endif

# You can still enable threads if you are adventurous. There
# are scientists like that. Not supported, but possible.
.if !empty(PKG_OPTIONS:Mhdf5-unsafe-threads)
CMAKE_CONFIGURE_ARGS+=	-DHDF5_ENABLE_THREADSAFE=ON #--enable-unsupported
.include "../../mk/pthread.buildlink3.mk"
.endif

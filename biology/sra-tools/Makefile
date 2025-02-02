# $NetBSD: Makefile,v 1.10 2025/02/02 14:25:34 bacon Exp $

DISTNAME=		sra-tools-3.2.0
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_GITHUB:=ncbi/}
GITHUB_SUBMODULES+=	ncbi ncbi-vdb ${PKGVERSION_NOREV} ncbi-vdb

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/ncbi/sra-tools
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
LICENSE=	public-domain AND gnu-lgpl-v2.1

# Upstream only supports specific platforms
ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash bison cmake

# SUBST edits may follow static patches.  Run "make clean patch" before
# updating those patches so SUBST changes do not get added to them.
SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-configure
SUBST_SED.etcdir+=	-e 's|"/etc/ncbi"|"${PREFIX}/etc/ncbi"|g'
SUBST_FILES.etcdir+=	ncbi-vdb/libs/kfg/config.c

SUBST_CLASSES+=		binpath
SUBST_STAGE.binpath=	pre-configure
SUBST_SED.binpath+=	-e 's|/usr/local|${PREFIX}|g'
SUBST_FILES.binpath+=	tools/external/driver-tool/file-path.posix.cpp

SUBST_CLASSES+=		submoddir
SUBST_STAGE.submoddir=	pre-configure
SUBST_SED.submoddir+=	-e 's|/../ncbi-vdb|/ncbi-vdb|g'
SUBST_FILES.submoddir+=	CMakeLists.txt

REPLACE_BASH=	*/*.sh */*/*.sh */*/*/*.sh */*/*/*/*.sh

CMAKE_CONFIGURE_ARGS+=		-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl	# ncbi-vdb/CMakeLists.posix.txt

.include "../../mk/bsd.prefs.mk"

# macOS does not support @rpath
.if ${OPSYS} == Darwin
SUBST_CLASSES+=		srarpath
SUBST_STAGE.srarpath=	post-configure
SUBST_SED.srarpath+=	-e 's|@rpath|${PREFIX}/lib|g'
SUBST_FILES.srarpath+=	cmake-pkgsrc-build/ngs/ngs-sdk/CMakeFiles/*/link.txt
.endif

pre-configure:
.if ${OPSYS} == NetBSD
	# Incorrect gcc/x86_64/byteswap.h found before correct bsd/byteswap.h
	# Adding #ifndef __NetBSD__ to gcc/x86_64/byteswap.h doesn't work
	# Still needed as of sra-tools 3.1.1
	${RM} -f ${WRKSRC}/ncbi-vdb/interfaces/cc/gcc/x86_64/byteswap.h
.endif
	cd ${WRKSRC}/ncbi-vdb/build && cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..
	cd ${WRKSRC}/ncbi-vdb/build && ${MAKE}

post-install:
	${STRIP} ${DESTDIR}${PREFIX}/bin/*.${PKGVERSION_NOREV}
	${STRIP} ${DESTDIR}${PREFIX}/lib/*.${PKGVERSION_NOREV}
	${RM} -rf ${DESTDIR}${PREFIX}/jar
	${RM} -rf ${DESTDIR}${PREFIX}/share/examples-java
	${RM} -rf ${DESTDIR}${PREFIX}/share/javadoc

.if ${OPSYS} != Linux && defined(OPSYS_HAS_KQUEUE)
.include "../../devel/libepoll-shim/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

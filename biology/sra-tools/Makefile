# $NetBSD: Makefile,v 1.4 2024/05/29 16:31:27 adam Exp $

DISTNAME=		sra-tools-3.0.6
PKGREVISION=		3
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=		984f1493e8612cd59a269569bf8c06e25e4e604c
GITHUB_SUBMODULES+=	outpaddling ncbi-vdb 38972fc ncbi-vdb

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/ncbi/sra-tools
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
LICENSE=	public-domain AND gnu-lgpl-v2.1

# Upstream only supports specific platforms
ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash bison cmake

# The config.c and file-path.posix.cpp substs follow
# static patches.  Run "make clean patch" before updating
# those patches so this subst does not get added to them.
SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-configure
SUBST_SED.etcdir+=	-e 's|"/etc/ncbi"|"${PREFIX}/etc/ncbi"|g'
SUBST_FILES.etcdir+=	ncbi-vdb/libs/kfg/config.c

SUBST_CLASSES+=		binpath
SUBST_STAGE.binpath=	pre-configure
SUBST_SED.binpath+=	-e 's|/usr/local/bin|${PREFIX}/bin|g'
SUBST_FILES.binpath+=	tools/external/driver-tool/file-path.posix.cpp

SUBST_CLASSES+=		submoddir
SUBST_STAGE.submoddir=	pre-configure
SUBST_SED.submoddir+=	-e 's|/../ncbi-vdb|/ncbi-vdb|g'
SUBST_FILES.submoddir+=	CMakeLists.txt

REPLACE_BASH=	*/*.sh */*/*.sh */*/*/*.sh */*/*/*/*.sh

USE_CMAKE=	yes
CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib
CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl	# ncbi-vdb/CMakeLists.posix.txt

EXAMPLESDIR=	${PREFIX}/share/examples/sra-tools

.include "../../mk/bsd.prefs.mk"

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
	${RM} -f ${WRKSRC}/ncbi-vdb/interfaces/cc/gcc/x86_64/byteswap.h
.endif
	cd ${WRKSRC}/ncbi-vdb/build && cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..
.if ${OPSYS} == Darwin
	# Unsure how to prevent cmake from emitting @rpath in the first place
	# No instances of @rpath or -install_name in any files before cmake
	for f in ${WRKSRC}/ncbi-vdb/build/libs/ncbi-vdb/CMakeFiles/*/link.txt; do \
		${SED} -e 's|@rpath|${PREFIX}/lib|g' $${f} > $${f}.tmp && ${MV} -f $${f}.tmp $${f}; \
	done
.endif
	cd ${WRKSRC}/ncbi-vdb/build && ${MAKE}

post-install:
	${STRIP} ${DESTDIR}${PREFIX}/bin/*.${PKGVERSION_NOREV}
	${MV} ${DESTDIR}${PREFIX}/share/examples ${DESTDIR}${PREFIX}/share/examples-sratools
	${MKDIR} ${DESTDIR}${EXAMPLESDIR}
	${MV} ${DESTDIR}${PREFIX}/share/examples-sratools/* ${DESTDIR}${EXAMPLESDIR}
	${RMDIR} ${DESTDIR}${PREFIX}/share/examples-sratools
	${MV} ${DESTDIR}${PREFIX}/share/examples-python ${DESTDIR}${EXAMPLESDIR}/python
	# FIXME: Can we prevent build from detecting java?
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

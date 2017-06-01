# $NetBSD: Makefile,v 1.8 2017/06/01 13:30:25 jlam Exp $

DISTNAME=	llvm-${PKGVERSION_NOREV}.src
PKGNAME=	libLLVM34-3.4.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure (previous version)

LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/llvm-${PKGVERSION_NOREV}.src
DESCR_SRC=		${.CURDIR}/../../lang/libLLVM/DESCR

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PYTHON_FOR_BUILD_ONLY=	yes
GCC_REQD+=		4.7 4.8
GNU_CONFIGURE=		yes
OVERRIDE_DIRDEPTH=	3
CONFIGURE_ARGS+=	--disable-assertions
CONFIGURE_ARGS+=	--disable-bindings
CONFIGURE_ARGS+=	--disable-timestamps
CONFIGURE_ARGS+=	--enable-optimized
CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		ENABLE_PIC=1
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/Release/lib

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm \
			utils/lit/utils/check-sdist \
			utils/lit/utils/check-coverage

TEST_TARGET=		check unittests
BUILD_TARGET=		libs-only
INSTALL_TARGET=		install-libs

SUBST_CLASSES+=		fix-pfx
SUBST_STAGE.fix-pfx=	pre-configure
SUBST_MESSAGE.fix-pfx=	Adjusting installation directories to avoid conflict with clang
SUBST_FILES.fix-pfx=	Makefile.config.in
SUBST_FILES.fix-pfx+=	cmake/modules/Makefile
SUBST_SED.fix-pfx=	-e 's,(PROJ_prefix)/bin$$,(PROJ_prefix)/libexec/libLLVM34,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/lib$$,(PROJ_prefix)/lib/libLLVM34,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/include$$,(PROJ_prefix)/include/libLLVM34,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/share/llvm/cmake$$,(PROJ_prefix)/share/libLLVM34/cmake,g'

SUBST_CLASSES+=		fix-cnf
SUBST_STAGE.fix-cnf=	pre-configure
SUBST_MESSAGE.fix-cnf=	Fixing llvm-config paths
SUBST_FILES.fix-cnf=	tools/llvm-config/llvm-config.cpp
SUBST_SED.fix-cnf=	-e 's|ActivePrefix + "/include"|"${PREFIX}/include/libLLVM34"|g'
SUBST_SED.fix-cnf+=	-e 's|ActivePrefix + "/lib"|"${PREFIX}/lib/libLLVM34"|g'
SUBST_SED.fix-cnf+=	-e 's|"-L" << ActiveLibDir|"${COMPILER_RPATH_FLAG}" << ActiveLibDir << " " << &|g'

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/libLLVM34

INSTALLATION_DIRS+=	lib/libLLVM34

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
# fixes unittest compilation
_WRAP_EXTRA_ARGS.CXX+=	-Wno-error=absolute-value
CWRAPPERS_APPEND.cxx+=	-Wno-error=absolute-value
.endif

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST_SUBST+=		SOEXT="so"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"

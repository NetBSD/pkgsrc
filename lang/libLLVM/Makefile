# $NetBSD: Makefile,v 1.7 2016/03/04 13:29:53 jperkin Exp $

PKGNAME=		${DISTNAME:S/clang/libLLVM/}

CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		ENABLE_PIC=1
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/Release/lib

BUILD_TARGET=		libs-only
INSTALL_TARGET=		install-libs
PYTHON_FOR_BUILD_ONLY=	yes

# for MesaLib
CONFIGURE_ARGS+=	 --enable-experimental-targets=AMDGPU

SUBST_CLASSES+=		fix-pfx
SUBST_STAGE.fix-pfx=	pre-configure
SUBST_MESSAGE.fix-pfx=	Adjusting installation directories to avoid conflict with clang
SUBST_FILES.fix-pfx=	Makefile.config.in
SUBST_FILES.fix-pfx+=	cmake/modules/Makefile
SUBST_SED.fix-pfx=	-e 's,(PROJ_prefix)/bin$$,(PROJ_prefix)/libexec/libLLVM,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/lib$$,(PROJ_prefix)/lib/libLLVM,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/include$$,(PROJ_prefix)/include/libLLVM,g'
SUBST_SED.fix-pfx+=	-e 's,(PROJ_prefix)/share/llvm/cmake$$,(PROJ_prefix)/share/libLLVM/cmake,g'

SUBST_CLASSES+=		fix-cnf
SUBST_STAGE.fix-cnf=	pre-configure
SUBST_MESSAGE.fix-cnf=	Fixing llvm-config paths
SUBST_FILES.fix-cnf=	tools/llvm-config/llvm-config.cpp
SUBST_SED.fix-cnf=	-e 's|ActivePrefix + "/include"|"${PREFIX}/include/libLLVM"|g'
SUBST_SED.fix-cnf+=	-e 's|ActivePrefix + "/lib" + LLVM_LIBDIR_SUFFIX|"${PREFIX}/lib/libLLVM"|g'
SUBST_SED.fix-cnf+=	-e 's|"-L" << ActiveLibDir|"${COMPILER_RPATH_FLAG}" << ActiveLibDir << " " << &|g'

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/libLLVM

INSTALLATION_DIRS+=	lib/libLLVM

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for lib in LLVMHello libLLVM-3.7; do \
		install_name_tool -id ${PREFIX}/lib/libLLVM/$${lib}.dylib \
		    ${DESTDIR}${PREFIX}/lib/libLLVM/$${lib}.dylib; \
	done
.endif

.include "../../lang/clang/Makefile.common"

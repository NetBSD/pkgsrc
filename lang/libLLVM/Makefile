# $NetBSD: Makefile,v 1.3 2015/04/25 20:20:32 tnn Exp $

PKGNAME=		${DISTNAME:S/clang/libLLVM/}
PKGREVISION=		1

CONFIGURE_ARGS+=	--enable-shared
MAKE_ENV+=		ENABLE_PIC=1
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/Release/lib

BUILD_TARGET=		libs-only
INSTALL_TARGET=		install-libs
PYTHON_FOR_BUILD_ONLY=	yes

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

# XXX temporary band-aid for wrapper reordering bug until we have a proper fix
#
# Wrappers incorrectly reorder:
#
# -Wl,--whole-archive -lmystaticlib -Wl,--no-whole-archive
#
# to
#
# -Wl,--whole-archive -Wl,--no-whole-archive -lmystaticlib
#
# Which nullies the effect of --whole-archive.
# Kludge around this by removing --no-whole-archive from the command line.
# It happens to be safe in this particular case, as far as I can tell.
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-whole-archive

.include "../../lang/clang/Makefile.common"

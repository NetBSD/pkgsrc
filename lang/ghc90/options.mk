# $NetBSD: options.mk,v 1.3 2021/07/14 09:15:35 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghc

.include "../../mk/bsd.prefs.mk"

# GHC has a native implementation of codegen for some platforms. On
# those platforms LLVM is optional. It's a requirement anywhere else.
# See compiler/GHC/Driver/Backend.hs

GHC_NCG_SUPPORTED=	i386 x86_64 powerpc powerpc64 sparc
.if !empty(GHC_NCG_SUPPORTED:M${MACHINE_ARCH})
PKG_SUPPORTED_OPTIONS+=	llvm
PKG_SUGGESTED_OPTIONS+=	llvm
GHC_LLVM_REQUIRED=	no
.else
GHC_LLVM_REQUIRED=	yes
.endif

.if !empty(PKG_SUPPORTED_OPTIONS)
.  include "../../mk/bsd.options.mk"
.endif

.if !empty(PKG_OPTIONS:Mllvm) || ${GHC_LLVM_REQUIRED} == "yes"
DEPENDS+=	llvm-[0-9]*:../../lang/llvm
CONFIGURE_ENV+=	LLC=${PREFIX:Q}/bin/llc
CONFIGURE_ENV+=	OPT=${PREFIX:Q}/bin/opt

# Maybe GHC doesn't like this but it's the only option available to us.
.  include "../../lang/llvm/version.mk"
SUBST_CLASSES+=		llvm
SUBST_STAGE.llvm=	post-extract
SUBST_MESSAGE.llvm=	Accept whichever version of LLVM installed via pkgsrc
SUBST_FILES.llvm=	configure.ac
SUBST_SED.llvm=		-e 's/LlvmVersion=[0-9]*/LlvmVersion=${LLVM_VERSION:C/^([0-9]*)\..*/\1/}/'

# Clang is also required on Darwin.
# See compiler/GHC/SysTools/Tasks.hs (runClang).
.  if ${OPSYS} == "Darwin"
DEPENDS+=	clang-[0-9]*:../../lang/clang
CONFIGURE_ENV+=	CLANG=${PREFIX:Q}/bin/clang
.  else
CONFIGURE_ENV+=	CLANG=${FALSE}
.  endif

.else
CONFIGURE_ENV+=	LLC=${FALSE:Q}
CONFIGURE_ENV+=	OPT=${FALSE:Q}
CONFIGURE_ENV+=	CLANG=${FALSE:Q}
.endif

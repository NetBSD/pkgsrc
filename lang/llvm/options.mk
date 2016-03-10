# $NetBSD: options.mk,v 1.1 2016/03/10 15:01:52 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.llvm

LLVM_TARGETS=	AArch64 AMDGPU ARM BPF CppBackend Hexagon MSP430 Mips NVPTX PowerPC Sparc SystemZ X86 XCore

.for tgt in ${LLVM_TARGETS}
PLIST_VARS+=			${tgt}
PKG_SUPPORTED_OPTIONS+=		llvm-target-${tgt:tl}
.endfor

# Probably safe to assume that only x86 users are interested in
# cross-compilation for now. This saves some build time for everyone else.
.if !empty(MACHINE_ARCH:Msparc*)
PKG_SUGGESTED_OPTIONS+=		llvm-target-sparc
.elif !empty(MACHINE_ARCH:Mpowerpc*)
PKG_SUGGESTED_OPTIONS+=		llvm-target-powerpc
.elif !empty(MACHINE_ARCH:Mearm*)
PKG_SUGGESTED_OPTIONS+=		llvm-target-arm
.elif !empty(MACHINE_ARCH:M*mips*)
PKG_SUGGESTED_OPTIONS+=		llvm-target-mips
.else
# X86 and everyone else get all targets by default.
.  for tgt in ${LLVM_TARGETS}
PKG_SUGGESTED_OPTIONS+=		llvm-target-${tgt:tl}
.  endfor
.endif

.include "../../mk/bsd.options.mk"

.for tgt in ${LLVM_TARGETS}
.  if !empty(PKG_OPTIONS:Mllvm-target-${tgt:tl})
PLIST.${tgt}=		yes
LLVM_TARGETS_TO_BUILD+=	${tgt}
.  endif
.endfor

CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD="${LLVM_TARGETS_TO_BUILD:ts;}"

# $NetBSD: options.mk,v 1.18 2024/05/10 17:22:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.llvm

LLVM_TARGETS=	AArch64 AMDGPU ARM AVR BPF Hexagon Lanai LoongArch Mips MSP430 NVPTX PowerPC RISCV Sparc SystemZ VE WebAssembly X86 XCore
LLVM_EXPERIMENTAL_TARGETS=	ARC CSKY DirectX M68k SPIRV Xtensa

.for tgt in ${LLVM_TARGETS} ${LLVM_EXPERIMENTAL_TARGETS}
PLIST_VARS+=			${tgt}
PKG_SUPPORTED_OPTIONS+=		llvm-target-${tgt:tl}
PRINT_PLIST_AWK+=		{if ($$0 ~ /libLLVM${tgt}/) {$$0 = "$${PLIST.${tgt}}" $$0;}}
PRINT_PLIST_AWK+=		{if ($$0 ~ /libLLVMExegesis${tgt}/) {$$0 = "$${PLIST.${tgt}}" $$0;}}
.endfor

PKG_SUPPORTED_OPTIONS+=		terminfo z3 tests debug

# Terminfo is used for colour output, only enable it by default if terminfo
# is builtin to avoid unnecessary dependencies which could cause bootstrap
# issues.
CHECK_BUILTIN.terminfo:=	yes
.include "../../mk/terminfo.builtin.mk"
CHECK_BUILTIN.terminfo:=	no
.if ${USE_BUILTIN.terminfo:tl} == yes
PKG_SUGGESTED_OPTIONS+=		terminfo
.endif

# Probably safe to assume that only x86 users are interested in
# cross-compilation for now. This saves some build time for everyone else.
.if ${MACHINE_ARCH:Msparc*}
PKG_SUGGESTED_OPTIONS+=	llvm-target-sparc
.elif ${MACHINE_ARCH:Mpowerpc*}
PKG_SUGGESTED_OPTIONS+=	llvm-target-powerpc
.elif ${MACHINE_ARCH:Mearm*}
PKG_SUGGESTED_OPTIONS+=	llvm-target-arm
.elif ${MACHINE_ARCH:M*mips*}
PKG_SUGGESTED_OPTIONS+=	llvm-target-mips
.else
# X86 and everyone else get all targets by default.
.  for tgt in ${LLVM_TARGETS} ${LLVM_EXPERIMENTAL_TARGETS}
PKG_SUGGESTED_OPTIONS+=	llvm-target-${tgt:tl}
.  endfor
.endif

.include "../../mk/bsd.options.mk"

.for tgt in ${LLVM_TARGETS}
.  if !empty(PKG_OPTIONS:Mllvm-target-${tgt:tl})
PLIST.${tgt}=		yes
LLVM_TARGETS_TO_BUILD+=	${tgt}
.  endif
.endfor

.for tgt in ${LLVM_EXPERIMENTAL_TARGETS}
.  if !empty(PKG_OPTIONS:Mllvm-target-${tgt:tl})
PLIST.${tgt}=	yes
LLVM_EXPERIMENTAL_TARGETS_TO_BUILD+=	${tgt}
.  endif
.endfor
.if !empty(LLVM_EXPERIMENTAL_TARGETS_TO_BUILD)
CMAKE_ARGS+=	-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD="${LLVM_EXPERIMENTAL_TARGETS_TO_BUILD:ts;}"
.endif

.if !empty(PKG_OPTIONS:Mterminfo)
.include "../../mk/terminfo.buildlink3.mk"
.else
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.endif

.if !empty(PKG_OPTIONS:Mz3)
.include "../../math/z3/buildlink3.mk"
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=ON
.endif

.if !empty(PKG_OPTIONS:Mdebug)
RELEASE_TYPE?=	debug
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
RELEASE_TYPE?=	release
.endif

.if !empty(PKG_OPTIONS:Mtests)
# requires "unittes" ?
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=ON
.else
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
.endif

CMAKE_ARGS+=	-DLLVM_TARGETS_TO_BUILD="${LLVM_TARGETS_TO_BUILD:ts;}"

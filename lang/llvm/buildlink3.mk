# $NetBSD: buildlink3.mk,v 1.26 2024/05/29 16:33:14 adam Exp $

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=17.0.0#<18
BUILDLINK_PKGSRCDIR.llvm?=	../../lang/llvm

LLVM_CONFIG_PATH?=		${BUILDLINK_PREFIX.llvm}/bin/llvm-config

BUILDLINK_FILES.llvm+=		bin/FileCheck
BUILDLINK_FILES.llvm+=		bin/UnicodeNameMappingGenerator
BUILDLINK_FILES.llvm+=		bin/bugpoint
BUILDLINK_FILES.llvm+=		bin/count
BUILDLINK_FILES.llvm+=		bin/dsymutil
BUILDLINK_FILES.llvm+=		bin/llc
BUILDLINK_FILES.llvm+=		bin/lli
BUILDLINK_FILES.llvm+=		bin/lli-child-target
BUILDLINK_FILES.llvm+=		bin/llvm-PerfectShuffle
BUILDLINK_FILES.llvm+=		bin/llvm-addr2line
BUILDLINK_FILES.llvm+=		bin/llvm-ar
BUILDLINK_FILES.llvm+=		bin/llvm-as
BUILDLINK_FILES.llvm+=		bin/llvm-bcanalyzer
BUILDLINK_FILES.llvm+=		bin/llvm-bitcode-strip
BUILDLINK_FILES.llvm+=		bin/llvm-c-test
BUILDLINK_FILES.llvm+=		bin/llvm-cat
BUILDLINK_FILES.llvm+=		bin/llvm-cfi-verify
BUILDLINK_FILES.llvm+=		bin/llvm-config
BUILDLINK_FILES.llvm+=		bin/llvm-cov
BUILDLINK_FILES.llvm+=		bin/llvm-cvtres
BUILDLINK_FILES.llvm+=		bin/llvm-cxxdump
BUILDLINK_FILES.llvm+=		bin/llvm-cxxfilt
BUILDLINK_FILES.llvm+=		bin/llvm-cxxmap
BUILDLINK_FILES.llvm+=		bin/llvm-debuginfo-analyzer
BUILDLINK_FILES.llvm+=		bin/llvm-debuginfod
BUILDLINK_FILES.llvm+=		bin/llvm-debuginfod-find
BUILDLINK_FILES.llvm+=		bin/llvm-diff
BUILDLINK_FILES.llvm+=		bin/llvm-dis
BUILDLINK_FILES.llvm+=		bin/llvm-dlltool
BUILDLINK_FILES.llvm+=		bin/llvm-dwarfdump
BUILDLINK_FILES.llvm+=		bin/llvm-dwarfutil
BUILDLINK_FILES.llvm+=		bin/llvm-dwp
BUILDLINK_FILES.llvm+=		bin/llvm-exegesis
BUILDLINK_FILES.llvm+=		bin/llvm-extract
BUILDLINK_FILES.llvm+=		bin/llvm-gsymutil
BUILDLINK_FILES.llvm+=		bin/llvm-ifs
BUILDLINK_FILES.llvm+=		bin/llvm-install-name-tool
BUILDLINK_FILES.llvm+=		bin/llvm-jitlink
BUILDLINK_FILES.llvm+=		bin/llvm-jitlink-executor
BUILDLINK_FILES.llvm+=		bin/llvm-lib
BUILDLINK_FILES.llvm+=		bin/llvm-libtool-darwin
BUILDLINK_FILES.llvm+=		bin/llvm-link
BUILDLINK_FILES.llvm+=		bin/llvm-lipo
BUILDLINK_FILES.llvm+=		bin/llvm-lit
BUILDLINK_FILES.llvm+=		bin/llvm-lto
BUILDLINK_FILES.llvm+=		bin/llvm-lto2
BUILDLINK_FILES.llvm+=		bin/llvm-mc
BUILDLINK_FILES.llvm+=		bin/llvm-mca
BUILDLINK_FILES.llvm+=		bin/llvm-ml
BUILDLINK_FILES.llvm+=		bin/llvm-modextract
BUILDLINK_FILES.llvm+=		bin/llvm-mt
BUILDLINK_FILES.llvm+=		bin/llvm-nm
BUILDLINK_FILES.llvm+=		bin/llvm-objcopy
BUILDLINK_FILES.llvm+=		bin/llvm-objdump
BUILDLINK_FILES.llvm+=		bin/llvm-opt-report
BUILDLINK_FILES.llvm+=		bin/llvm-otool
BUILDLINK_FILES.llvm+=		bin/llvm-pdbutil
BUILDLINK_FILES.llvm+=		bin/llvm-profdata
BUILDLINK_FILES.llvm+=		bin/llvm-profgen
BUILDLINK_FILES.llvm+=		bin/llvm-ranlib
BUILDLINK_FILES.llvm+=		bin/llvm-rc
BUILDLINK_FILES.llvm+=		bin/llvm-readelf
BUILDLINK_FILES.llvm+=		bin/llvm-readobj
BUILDLINK_FILES.llvm+=		bin/llvm-reduce
BUILDLINK_FILES.llvm+=		bin/llvm-remark-size-diff
BUILDLINK_FILES.llvm+=		bin/llvm-remarkutil
BUILDLINK_FILES.llvm+=		bin/llvm-rtdyld
BUILDLINK_FILES.llvm+=		bin/llvm-sim
BUILDLINK_FILES.llvm+=		bin/llvm-size
BUILDLINK_FILES.llvm+=		bin/llvm-split
BUILDLINK_FILES.llvm+=		bin/llvm-stress
BUILDLINK_FILES.llvm+=		bin/llvm-strings
BUILDLINK_FILES.llvm+=		bin/llvm-strip
BUILDLINK_FILES.llvm+=		bin/llvm-symbolizer
BUILDLINK_FILES.llvm+=		bin/llvm-tapi-diff
BUILDLINK_FILES.llvm+=		bin/llvm-tblgen
BUILDLINK_FILES.llvm+=		bin/llvm-tli-checker
BUILDLINK_FILES.llvm+=		bin/llvm-undname
BUILDLINK_FILES.llvm+=		bin/llvm-windres
BUILDLINK_FILES.llvm+=		bin/llvm-xray
BUILDLINK_FILES.llvm+=		bin/not
BUILDLINK_FILES.llvm+=		bin/obj2yaml
BUILDLINK_FILES.llvm+=		bin/opt
BUILDLINK_FILES.llvm+=		bin/sancov
BUILDLINK_FILES.llvm+=		bin/sanstats
BUILDLINK_FILES.llvm+=		bin/split-file
BUILDLINK_FILES.llvm+=		bin/verify-uselistorder
BUILDLINK_FILES.llvm+=		bin/yaml-bench
BUILDLINK_FILES.llvm+=		bin/yaml2obj

pkgbase := llvm
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.llvm:Mterminfo}
.include "../../mk/terminfo.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.llvm:Mz3}
.include "../../math/z3/buildlink3.mk"
.endif

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm

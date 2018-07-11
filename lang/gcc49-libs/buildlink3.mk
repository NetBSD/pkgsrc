# $NetBSD: buildlink3.mk,v 1.4 2018/07/11 11:21:26 jperkin Exp $

BUILDLINK_TREE+=	gcc49-libs

.if !defined(GCC49_LIBS_BUILDLINK3_MK)
GCC49_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc49-libs+=	gcc49-libs>=4.9.1
.else
BUILDLINK_API_DEPENDS.gcc49-libs+=	{gcc49,gcc49-libs}>=4.9.1
.endif
BUILDLINK_PKGSRCDIR.gcc49-libs=		../../lang/gcc49-libs
BUILDLINK_DEPMETHOD.gcc49-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc49-libs}/gcc49

BUILDLINK_FILES.gcc49-libs=	#empty
BUILDLINK_AUTO_VARS.gcc49-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc49
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc49-libs}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

# On Darwin we need to modify the libgcc linkage, by default it will try to
# use stub libraries which we cannot change the library name for, leading to
# check-shlibs failures as it thinks they come from the main gcc49 package.
${SPECS_LIBGCC}:
	@${ECHO} "*link_libgcc:" >${SPECS_LIBGCC}
	@${ECHO} "%D ${LINKER_RPATH_FLAG}${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE}/lib/%M" >>${SPECS_LIBGCC}
.  if ${OPSYS} == "Darwin"
	@${ECHO} "" >>${SPECS_LIBGCC}
	@${ECHO} "*libgcc:" >>${SPECS_LIBGCC}
	@${ECHO} "%{static-libgcc|static: -lgcc_eh -lgcc; shared-libgcc|fexceptions|fgnu-runtime: -lgcc; : -lgcc }" >>${SPECS_LIBGCC}
.  endif

_WRAP_EXTRA_ARGS.CC+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.CXX+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.FC+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cc+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cxx+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.f77+=	-specs=${SPECS_LIBGCC}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC49_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc49-libs

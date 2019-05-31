# $NetBSD: buildlink3.mk,v 1.2 2019/05/31 09:23:57 kamil Exp $

BUILDLINK_TREE+=	gcc8-libs

.if !defined(GCC8_LIBS_BUILDLINK3_MK)
GCC8_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc8-libs+=	gcc8-libs>=8.3.0
.else
BUILDLINK_API_DEPENDS.gcc8-libs+=	{gcc8,gcc8-libs}>=8.3.0
.endif
BUILDLINK_PKGSRCDIR.gcc8-libs=		../../lang/gcc8-libs
BUILDLINK_DEPMETHOD.gcc8-libs?=		full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc8-libs}/gcc8

BUILDLINK_FILES.gcc8-libs=	#empty
BUILDLINK_AUTO_VARS.gcc8-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc8
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc8-libs}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

${SPECS_LIBGCC}:
	@${ECHO} "*link_libgcc:" >${SPECS_LIBGCC}
	@${ECHO} "%D ${LINKER_RPATH_FLAG}${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE}/lib/%M" >>${SPECS_LIBGCC}

_WRAP_EXTRA_ARGS.CC+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.CXX+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.FC+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cc+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cxx+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.f77+=	-specs=${SPECS_LIBGCC}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC8_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc8-libs

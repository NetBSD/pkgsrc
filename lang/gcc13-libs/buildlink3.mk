# $NetBSD: buildlink3.mk,v 1.1 2023/05/03 20:03:42 wiz Exp $

BUILDLINK_TREE+=	gcc13-libs

.if !defined(GCC13_LIBS_BUILDLINK3_MK)
GCC13_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc13-libs+=	gcc13-libs>=13.1.0
.else
BUILDLINK_API_DEPENDS.gcc13-libs+=	{gcc13,gcc13-libs}>=13.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc13-libs=		../../lang/gcc13-libs
BUILDLINK_DEPMETHOD.gcc13-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc13-libs}/gcc13

BUILDLINK_FILES.gcc13-libs=	#empty
BUILDLINK_AUTO_VARS.gcc13-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc13
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc13-libs}/${LIBGCC_SUBPREFIX}
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
.endif # GCC13_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc13-libs

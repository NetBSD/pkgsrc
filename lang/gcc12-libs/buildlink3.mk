# $NetBSD: buildlink3.mk,v 1.1 2022/06/16 15:43:55 adam Exp $

BUILDLINK_TREE+=	gcc12-libs

.if !defined(GCC12_LIBS_BUILDLINK3_MK)
GCC12_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc12-libs+=	gcc12-libs>=12.1.0
.else
BUILDLINK_API_DEPENDS.gcc12-libs+=	{gcc12,gcc12-libs}>=12.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc12-libs=		../../lang/gcc12-libs
BUILDLINK_DEPMETHOD.gcc12-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc12-libs}/gcc12

BUILDLINK_FILES.gcc12-libs=	#empty
BUILDLINK_AUTO_VARS.gcc12-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc12
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc12-libs}/${LIBGCC_SUBPREFIX}
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
.endif # GCC12_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc12-libs

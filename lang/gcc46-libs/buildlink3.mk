# $NetBSD: buildlink3.mk,v 1.2 2015/02/04 14:16:23 jperkin Exp $

BUILDLINK_TREE+=	gcc46-libs

.if !defined(GCC46_LIBS_BUILDLINK3_MK)
GCC46_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc46-libs+=	gcc46-libs>=4.6.0
.else
BUILDLINK_API_DEPENDS.gcc46-libs+=	{gcc46,gcc46-libs}>=4.6.0
.endif
BUILDLINK_PKGSRCDIR.gcc46-libs=		../../lang/gcc46-libs
BUILDLINK_DEPMETHOD.gcc46-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc46-libs}/gcc46

BUILDLINK_FILES.gcc46-libs=	#empty
BUILDLINK_AUTO_VARS.gcc46-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc46
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc46-libs}/${LIBGCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

# XXX: Using %M requires patched version of gcc (e.g. lang/gcc46)
${SPECS_LIBGCC}:
	@${ECHO} "*link_libgcc:" >${SPECS_LIBGCC}
	@${ECHO} "%D $(LINKER_RPATH_FLAG)${LIBGCC_PREFIX}/${GCC_TARGET_MACHINE}/lib/%M" >>${SPECS_LIBGCC}

_WRAP_EXTRA_ARGS.CC+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.CXX+=	-specs=${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.FC+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cc+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.cxx+=	-specs=${SPECS_LIBGCC}
CWRAPPERS_APPEND.f77+=	-specs=${SPECS_LIBGCC}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC46_LIBS_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc46-libs

# $NetBSD: buildlink3.mk,v 1.4 2013/06/14 08:53:26 jperkin Exp $

BUILDLINK_TREE+=	gcc48-libs

.if !defined(GCC48_LIBS_BUILDLINK3_MK)
GCC48_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc48-libs+=	gcc48-libs>=4.8.0
.else
BUILDLINK_API_DEPENDS.gcc48-libs+=	{gcc48,gcc48-libs}>=4.8.0
.endif
BUILDLINK_PKGSRCDIR.gcc48-libs=		../../lang/gcc48-libs
BUILDLINK_DEPMETHOD.gcc48-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc48-libs}/gcc48

BUILDLINK_FILES.gcc48-libs=	#empty
BUILDLINK_AUTO_VARS.gcc48-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc48
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc48-libs}/${LIBGCC_SUBPREFIX}
LIBGCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

# XXX: Using %M requires patched version of gcc (e.g. lang/gcc48)
${SPECS_LIBGCC}:
	@${ECHO} "*link_libgcc:" >${SPECS_LIBGCC}
	@${ECHO} "%D $(LINKER_RPATH_FLAG)${LIBGCC_PREFIX}/${LIBGCC_TARGET_MACHINE}/lib/%M" >>${SPECS_LIBGCC}

_WRAP_EXTRA_ARGS.CC+=	-specs ${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.CXX+=	-specs ${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.FC+=	-specs ${SPECS_LIBGCC}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC48_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc48-libs

# $NetBSD: buildlink3.mk,v 1.7 2013/06/13 10:39:43 jperkin Exp $

BUILDLINK_TREE+=	gcc47-libs

.if !defined(GCC47_LIBS_BUILDLINK3_MK)
GCC47_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc47-libs+=	gcc47-libs>=4.7.0
.else
BUILDLINK_API_DEPENDS.gcc47-libs+=	{gcc47,gcc47-libs}>=4.7.0
.endif
BUILDLINK_PKGSRCDIR.gcc47-libs=		../../lang/gcc47-libs
BUILDLINK_DEPMETHOD.gcc47-libs?=	full

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc47-libs}/gcc47

BUILDLINK_FILES.gcc47-libs=	#empty
BUILDLINK_AUTO_VARS.gcc47-libs=	no

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
# Use custom specs file to ensure we link against pkgsrc libraries.
SPECS_LIBGCC=		${WRAPPER_DIR}/specs.libgcc
WRAPPER_TARGETS+=	${SPECS_LIBGCC}

LIBGCC_SUBPREFIX=	gcc47
LIBGCC_PREFIX=		${BUILDLINK_PREFIX.gcc47-libs}/${LIBGCC_SUBPREFIX}
LIBGCC_TARGET_MACHINE?= ${MACHINE_GNU_PLATFORM}

# XXX: Using %M requires patched version of gcc (e.g. lang/gcc47)
${SPECS_LIBGCC}:
	@${ECHO} "*link_libgcc:" >${SPECS_LIBGCC}
	@${ECHO} "%D $(LINKER_RPATH_FLAG)${LIBGCC_PREFIX}/${LIBGCC_TARGET_MACHINE}/lib/%M $(LINKER_RPATH_FLAG)${LIBGCC_PREFIX}/lib/%M" >>${SPECS_LIBGCC}

_WRAP_EXTRA_ARGS.CC+=	-specs ${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.CXX+=	-specs ${SPECS_LIBGCC}
_WRAP_EXTRA_ARGS.FC+=	-specs ${SPECS_LIBGCC}
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC47_LIBS_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc47-libs

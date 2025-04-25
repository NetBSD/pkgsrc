# $NetBSD: buildlink3.mk,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

BUILDLINK_TREE+=	gcc14-gnat

.if !defined(GCC14_GNAT_BUILDLINK3_MK)
GCC14_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14
BUILDLINK_ABI_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14.1
BUILDLINK_PKGSRCDIR.gcc14-gnat=		../../lang/gcc14-gnat
BUILDLINK_DEPMETHOD.gcc14-gnat?=	build

PREPEND_PATH+=	${BUILDLINK_DIR}/gcc14-gnat/bin

GNU_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

ADALIB_PREFIX=	gcc14-gnat/lib/gcc/${GNU_TARGET_MACHINE}/14.2.0

BUILDLINK_FILES.gcc14-gnat+=	gcc14-gnat/${GNU_TARGET_MACHINE}/lib/*

BUILDLINK_INCDIRS.gcc14-gnat+=	gcc14-gnat/include
BUILDLINK_INCDIRS.gcc14-gnat+=	${ADALIB_PREFIX}/include
BUILDLINK_INCDIRS.gcc14-gnat+=	${ADALIB_PREFIX}/include-fixed
BUILDLINK_INCDIRS.gcc14-gnat+=	${ADALIB_PREFIX}/plugin/include
BUILDLINK_INCDIRS.gcc14-gnat+=	${ADALIB_PREFIX}/adainclude

BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/lib
BUILDLINK_LIBDIRS.gcc14-gnat+=	${ADALIB_PREFIX}
BUILDLINK_LIBDIRS.gcc14-gnat+=	${ADALIB_PREFIX}/adalib
BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/${GNU_TARGET_MACHINE}/lib

BUILDLINK_CONTENTS_FILTER.gcc14-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*|${GNU_TARGET_MACHINE}/lib/.*)'

pkgbase := gcc14-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc14-gnat

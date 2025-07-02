# $NetBSD: buildlink3.mk,v 1.4 2025/07/02 18:09:02 dkazankov Exp $

BUILDLINK_TREE+=	gcc13-gnat

.if !defined(GCC13_GNAT_BUILDLINK3_MK)
GCC13_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.1.0
BUILDLINK_ABI_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.4.0
BUILDLINK_PKGSRCDIR.gcc13-gnat=		../../lang/gcc13-gnat
BUILDLINK_DEPMETHOD.gcc13-gnat?=	build

PREPEND_PATH+=	${BUILDLINK_DIR}/gcc13-gnat/bin

GNU_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

ADALIB_PREFIX=		gcc13-gnat/lib/gcc/${GNU_TARGET_MACHINE}/13.4.0

BUILDLINK_FILES.gcc13-gnat+=	gcc13-gnat/${GNU_TARGET_MACHINE}/lib/*

BUILDLINK_INCDIRS.gcc13-gnat+=	gcc13-gnat/include
BUILDLINK_INCDIRS.gcc13-gnat+=	${ADALIB_PREFIX}/include
BUILDLINK_INCDIRS.gcc13-gnat+=	${ADALIB_PREFIX}/include-fixed
BUILDLINK_INCDIRS.gcc13-gnat+=	${ADALIB_PREFIX}/plugin/include
BUILDLINK_INCDIRS.gcc13-gnat+=	${ADALIB_PREFIX}/adainclude

BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/lib
BUILDLINK_LIBDIRS.gcc13-gnat+=	${ADALIB_PREFIX}
BUILDLINK_LIBDIRS.gcc13-gnat+=	${ADALIB_PREFIX}/adalib
BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/${GNU_TARGET_MACHINE}/lib

BUILDLINK_CONTENTS_FILTER.gcc13-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*|${GNU_TARGET_MACHINE}/lib/.*)'

pkgbase := gcc13-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc13-gnat

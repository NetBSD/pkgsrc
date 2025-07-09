# $NetBSD: buildlink3.mk,v 1.5 2025/07/09 17:10:43 dkazankov Exp $

BUILDLINK_TREE+=	gcc13-gnat

.if !defined(GCC13_GNAT_BUILDLINK3_MK)
GCC13_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.1.0
BUILDLINK_ABI_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.4.0
BUILDLINK_PKGSRCDIR.gcc13-gnat?=	../../lang/gcc13-gnat
BUILDLINK_DEPMETHOD.gcc13-gnat?=	build

ADALIB_BASE=		lib/gcc/${MACHINE_GNU_PLATFORM}/13.4.0

BUILDLINK_FNAME_TRANSFORM.gcc13-gnat+=	-e "s|^${BUILDLINK_DIR}/gcc13-gnat/|${BUILDLINK_DIR}/|g"

BUILDLINK_INCDIRS.gcc13-gnat+=	gcc13-gnat/include
BUILDLINK_INCDIRS.gcc13-gnat+=	gcc13-gnat/${ADALIB_BASE}/include
BUILDLINK_INCDIRS.gcc13-gnat+=	gcc13-gnat/${ADALIB_BASE}/adainclude

BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/lib
BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/${ADALIB_BASE}
BUILDLINK_LIBDIRS.gcc13-gnat+=	gcc13-gnat/${ADALIB_BASE}/adalib

BUILDLINK_CONTENTS_FILTER.gcc13-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*)'

pkgbase := gcc13-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc13-gnat

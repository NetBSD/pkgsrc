# $NetBSD: buildlink3.mk,v 1.7 2025/10/15 20:04:57 dkazankov Exp $

BUILDLINK_TREE+=	gcc13-gnat

.if !defined(GCC13_GNAT_BUILDLINK3_MK)
GCC13_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.1.0
BUILDLINK_ABI_DEPENDS.gcc13-gnat+=	gcc13-gnat>=13.4.0
BUILDLINK_PKGSRCDIR.gcc13-gnat?=	../../lang/gcc13-gnat
BUILDLINK_DEPMETHOD.gcc13-gnat?=	build

ADA_PROJECT_PATH=	${BUILDLINK_DIR}/lib/gnat
MAKE_ENV+=		ADA_PROJECT_PATH=${ADA_PROJECT_PATH:Q}

ADALIB_BASE=		lib/gcc/${MACHINE_GNU_PLATFORM}/13.4.0

ADA_INCLUDE_PATH=	${BUILDLINK_DIR}/include:${BUILDLINK_DIR}/${ADALIB_BASE}/adainclude:${BUILDLINK_DIR}/${ADALIB_BASE}/include
MAKE_ENV+=		ADA_INCLUDE_PATH=${ADA_INCLUDE_PATH:Q}

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

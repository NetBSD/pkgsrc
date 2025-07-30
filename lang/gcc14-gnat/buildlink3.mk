# $NetBSD: buildlink3.mk,v 1.4 2025/07/30 19:22:48 dkazankov Exp $

BUILDLINK_TREE+=	gcc14-gnat

.if !defined(GCC14_GNAT_BUILDLINK3_MK)
GCC14_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14.1.0
BUILDLINK_ABI_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14.3.0
BUILDLINK_PKGSRCDIR.gcc14-gnat?=	../../lang/gcc14-gnat
BUILDLINK_DEPMETHOD.gcc14-gnat?=	build

ADA_PROJECT_PATH=	${BUILDLINK_DIR}/lib/gnat
MAKE_ENV+=		ADA_PROJECT_PATH=${ADA_PROJECT_PATH}

ADALIB_BASE=		lib/gcc/${MACHINE_GNU_PLATFORM}/14.3.0

ADA_INCLUDE_PATH=	${BUILDLINK_DIR}/include:${BUILDLINK_DIR}/${ADALIB_BASE}/adainclude:${BUILDLINK_DIR}/${ADALIB_BASE}/include
MAKE_ENV+=		ADA_INCLUDE_PATH=${ADA_INCLUDE_PATH}

BUILDLINK_FNAME_TRANSFORM.gcc14-gnat+=	-e "s|^${BUILDLINK_DIR}/gcc14-gnat/|${BUILDLINK_DIR}/|g"

BUILDLINK_INCDIRS.gcc14-gnat+=	gcc14-gnat/include
BUILDLINK_INCDIRS.gcc14-gnat+=	gcc14-gnat/${ADALIB_BASE}/include
BUILDLINK_INCDIRS.gcc14-gnat+=	gcc14-gnat/${ADALIB_BASE}/adainclude

BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/lib
BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/${ADALIB_BASE}
BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/${ADALIB_BASE}/adalib

BUILDLINK_CONTENTS_FILTER.gcc14-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*)'

pkgbase := gcc14-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc14-gnat

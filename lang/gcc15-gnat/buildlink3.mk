# $NetBSD: buildlink3.mk,v 1.3 2025/08/27 18:59:44 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-gnat

.if !defined(GCC15_GNAT_BUILDLINK3_MK)
GCC15_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15-gnat+=	gcc15-gnat>=15.1.0
BUILDLINK_PKGSRCDIR.gcc15-gnat?=	../../lang/gcc15-gnat
BUILDLINK_DEPMETHOD.gcc15-gnat?=	build

ADA_PROJECT_PATH=	${BUILDLINK_DIR}/lib/gnat
MAKE_ENV+=		ADA_PROJECT_PATH=${ADA_PROJECT_PATH}

ADALIB_BASE=		lib/gcc/${MACHINE_GNU_PLATFORM}/15.2.0

ADA_INCLUDE_PATH=	${BUILDLINK_DIR}/include:${BUILDLINK_DIR}/${ADALIB_BASE}/adainclude:${BUILDLINK_DIR}/${ADALIB_BASE}/include
MAKE_ENV+=		ADA_INCLUDE_PATH=${ADA_INCLUDE_PATH}

BUILDLINK_FNAME_TRANSFORM.gcc15-gnat+=	-e "s|^${BUILDLINK_DIR}/gcc15-gnat/|${BUILDLINK_DIR}/|g"

BUILDLINK_INCDIRS.gcc15-gnat+=	gcc15-gnat/include
BUILDLINK_INCDIRS.gcc15-gnat+=	gcc15-gnat/${ADALIB_BASE}/include
BUILDLINK_INCDIRS.gcc15-gnat+=	gcc15-gnat/${ADALIB_BASE}/adainclude

BUILDLINK_LIBDIRS.gcc15-gnat+=	gcc15-gnat/lib
BUILDLINK_LIBDIRS.gcc15-gnat+=	gcc15-gnat/${ADALIB_BASE}
BUILDLINK_LIBDIRS.gcc15-gnat+=	gcc15-gnat/${ADALIB_BASE}/adalib

BUILDLINK_CONTENTS_FILTER.gcc15-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*)'

pkgbase := gcc15-gnat
.include "../../mk/pkg-build-options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif

BUILDLINK_TREE+=	-gcc15-gnat

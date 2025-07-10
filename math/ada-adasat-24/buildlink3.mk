# $NetBSD: buildlink3.mk,v 1.1 2025/07/10 14:03:15 dkazankov Exp $

BUILDLINK_TREE+=	adasat-24

.if !defined(ADASAT_24_BUILDLINK3_MK)
ADASAT_24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adasat-24+=	adasat-${GNAT_NAME}>=24.0.0
BUILDLINK_PKGSRCDIR.adasat-24?=		../../math/ada-adasat-24
BUILDLINK_DEPMETHOD.adasat-24?=		build

BUILDLINK_CONTENTS_FILTER.adasat-24=	\
    ${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.adasat-24+=	\
    -e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"


.endif

BUILDLINK_TREE+=	-adasat-24

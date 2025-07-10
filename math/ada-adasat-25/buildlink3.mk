# $NetBSD: buildlink3.mk,v 1.1 2025/07/10 15:47:58 dkazankov Exp $

BUILDLINK_TREE+=	adasat-25

.if !defined(ADASAT_25_BUILDLINK3_MK)
ADASAT_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adasat-25+=	adasat-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.adasat-25?=		../../math/ada-adasat-25
BUILDLINK_DEPMETHOD.adasat-25?=		build

BUILDLINK_CONTENTS_FILTER.adasat-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.adasat-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-adasat-25

# $NetBSD: buildlink3.mk,v 1.1 2026/06/08 07:39:43 dkazankov Exp $

BUILDLINK_TREE+=	ada-adasat26

.if !defined(ADA_ADASAT26_BUILDLINK3_MK)
ADA_ADASAT26_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ada-adasat26+=	ada-adasat-${GNAT_NAME}>=26.0.0
BUILDLINK_PKGSRCDIR.ada-adasat26?=		../../math/ada-adasat26
BUILDLINK_DEPMETHOD.ada-adasat26?=		build

BUILDLINK_CONTENTS_FILTER.ada-adasat26=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.ada-adasat26+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-ada-adasat26

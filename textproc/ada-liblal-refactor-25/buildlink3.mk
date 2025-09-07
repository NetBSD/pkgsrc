# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:31:38 dkazankov Exp $

BUILDLINK_TREE+=	liblal-refactor-25

.if !defined(LIBLAL_REFACTOR_25_BUILDLINK3_MK)
LIBLAL_REFACTOR_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblal-refactor-25+=	liblal-refactor-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.liblal-refactor-25?=	../../textproc/ada-liblal-refactor-25
BUILDLINK_DEPMETHOD.liblal-refactor-25?=	build

BUILDLINK_CONTENTS_FILTER.liblal-refactor-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.liblal-refactor-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-liblal-refactor-25

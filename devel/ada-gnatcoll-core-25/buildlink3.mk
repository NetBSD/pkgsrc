# $NetBSD: buildlink3.mk,v 1.1 2025/07/10 18:52:41 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-core-25

.if !defined(GNATCOLL_CORE_25_BUILDLINK3_MK)
GNATCOLL_CORE_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-core-25+=	gnatcoll-core-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-core-25?=		../../devel/ada-gnatcoll-core-25
BUILDLINK_DEPMETHOD.gnatcoll-core-25?=		build

BUILDLINK_CONTENTS_FILTER.gnatcoll-core-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnatcoll-core-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-gnatcoll-core-25

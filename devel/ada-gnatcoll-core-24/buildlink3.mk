# $NetBSD: buildlink3.mk,v 1.2 2025/07/10 15:32:15 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-core-24

.if !defined(GNATCOLL_CORE_24_BUILDLINK3_MK)
GNATCOLL_CORE_24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-core-24+=	gnatcoll-core-${GNAT_NAME}>=24.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-core-24?=		../../devel/ada-gnatcoll-core-24
BUILDLINK_DEPMETHOD.gnatcoll-core-24?=		build

BUILDLINK_CONTENTS_FILTER.gnatcoll-core-24=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnatcoll-core-24+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-gnatcoll-core-24

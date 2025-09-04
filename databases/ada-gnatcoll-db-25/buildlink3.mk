# $NetBSD: buildlink3.mk,v 1.2 2025/09/04 07:22:58 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-db-25

.if !defined(GNATCOLL_DB_25_BUILDLINK3_MK)
GNATCOLL_DB_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-db-25+=	gnatcoll-db-${GNAT_NAME}>=24.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-db-25?=	../../databases/ada-gnatcoll-db-25
BUILDLINK_DEPMETHOD.gnatcoll-db-25?=	build

BUILDLINK_CONTENTS_FILTER.gnatcoll-db-25=	\
	${EGREP} "${GNAT_PKGBASE}/bin/.*$$|${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnatcoll-db-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

pkgbase := gnatcoll-db-25
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gnatcoll-db-25

# $NetBSD: buildlink3.mk,v 1.3 2025/10/09 19:50:12 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-db-25

.if !defined(GNATCOLL_DB_25_BUILDLINK3_MK)
GNATCOLL_DB_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-db-25+=	gnatcoll-db-${GNAT_NAME}>=25.0.0
BUILDLINK_ABI_DEPENDS.gnatcoll-db-25+=	gnatcoll-db-${GNAT_NAME}>=25.2.0
BUILDLINK_PKGSRCDIR.gnatcoll-db-25?=	../../databases/ada-gnatcoll-db-25
BUILDLINK_DEPMETHOD.gnatcoll-db-25?=	build

BUILDLINK_CONTENTS_FILTER.gnatcoll-db-25=	\
	${EGREP} "${GNAT_PKGBASE}/bin/.*$$|${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnatcoll-db-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

pkgbase := gnatcoll-db-25
.include "../../mk/pkg-build-options.mk"

.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-postgres} || \
    ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-xref} || \
    ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-gnatinspect}
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-postgres} || \
    ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-postgres2ada} || \
    ${PKG_BUILD_OPTIONS.gnatcoll-db-25:Mgnatcoll-all2ada}
.include "../../mk/pgsql.buildlink3.mk"
.endif

.endif

BUILDLINK_TREE+=	-gnatcoll-db-25

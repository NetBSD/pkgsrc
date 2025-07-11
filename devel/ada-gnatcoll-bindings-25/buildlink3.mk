# $NetBSD: buildlink3.mk,v 1.1 2025/07/11 12:46:49 dkazankov Exp $

BUILDLINK_TREE+=	gnatcoll-bindings-25

.if !defined(GNATCOLL_BINDINGS_25_BUILDLINK3_MK)
GNATCOLL_BINDINGS_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnatcoll-bindings-25+=	gnatcoll-bindings-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.gnatcoll-bindings-25?=	../../devel/ada-gnatcoll-bindings-25
BUILDLINK_DEPMETHOD.gnatcoll-bindings-25?=	build

BUILDLINK_CONTENTS_FILTER.gnatcoll-bindings-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnatcoll-bindings-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

pkgbase := gnatcoll-bindings-25
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-gnatcoll-bindings-25

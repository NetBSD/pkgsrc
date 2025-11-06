# $NetBSD: buildlink3.mk,v 1.3 2025/11/06 06:45:21 dkazankov Exp $

BUILDLINK_TREE+=	langkit-support-25

.if !defined(LANGKIT_SUPPORT_25_BUILDLINK3_MK)
LANGKIT_SUPPORT_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.langkit-support-25+=	langkit-support-${GNAT_NAME}>=25.0.0
BUILDLINK_ABI_DEPENDS.langkit-support-25+=	langkit-support-${GNAT_NAME}>=25.2.0
BUILDLINK_PKGSRCDIR.langkit-support-25?=	../../devel/ada-langkit-support-25
BUILDLINK_DEPMETHOD.langkit-support-25?=	build

BUILDLINK_CONTENTS_FILTER.langkit-support-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.langkit-support-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"

.endif

BUILDLINK_TREE+=	-langkit-support-25

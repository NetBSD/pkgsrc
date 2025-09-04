# $NetBSD: buildlink3.mk,v 1.1 2025/09/04 11:17:42 dkazankov Exp $

BUILDLINK_TREE+=	langkit-support-25

.if !defined(LANGKIT_SUPPORT_25_BUILDLINK3_MK)
LANGKIT_SUPPORT_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.langkit-support-25+=	langkit-support-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.langkit-support-25?=	../../devel/ada-langkit-support-25
BUILDLINK_DEPMETHOD.langkit-support-25?=	build

BUILDLINK_CONTENTS_FILTER.langkit-support-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.langkit-support-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-langkit-support-25

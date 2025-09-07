# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:13:53 dkazankov Exp $

BUILDLINK_TREE+=	liblal-tools-25

.if !defined(LIBLAL_TOOLS_25_BUILDLINK3_MK)
LIBLAL_TOOLS_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblal-tools-25+=	liblal-tools-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.liblal-tools-25?=	../../devel/ada-liblal-tools-25
BUILDLINK_DEPMETHOD.liblal-tools-25?=	build

BUILDLINK_CONTENTS_FILTER.liblal-tools-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.liblal-tools-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-liblal-tools-25

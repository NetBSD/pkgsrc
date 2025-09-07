# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:42:08 dkazankov Exp $

BUILDLINK_TREE+=	markdown-25

.if !defined(MARKDOWN_25_BUILDLINK3_MK)
MARKDOWN_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.markdown-25+=	markdown-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.markdown-25?=	../../textproc/ada-markdown-25
BUILDLINK_DEPMETHOD.markdown-25?=	build

BUILDLINK_CONTENTS_FILTER.markdown-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.markdown-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-markdown-25

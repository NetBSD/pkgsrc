# $NetBSD: buildlink3.mk,v 1.1 2025/09/04 10:44:40 dkazankov Exp $

BUILDLINK_TREE+=	templates-parser-25

.if !defined(TEMPLATES_PARSER_25_BUILDLINK3_MK)
TEMPLATES_PARSER_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.templates-parser-25+=	templates-parser-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.templates-parser-25?=	../../textproc/ada-templates-parser-25
BUILDLINK_DEPMETHOD.templates-parser-25?=	build

BUILDLINK_CONTENTS_FILTER.templates-parser-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.templates-parser-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-templates-parser-25

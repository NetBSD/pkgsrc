# $NetBSD: buildlink3.mk,v 1.2 2025/09/04 08:20:02 dkazankov Exp $

BUILDLINK_TREE+=	xmlada-25

.if !defined(XMLADA_25_BUILDLINK3_MK)
XMLADA_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlada-25+=	xmlada-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.xmlada-25?=		../../textproc/ada-xmlada-25
BUILDLINK_DEPMETHOD.xmlada-25?=		build

BUILDLINK_CONTENTS_FILTER.xmlada-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.xmlada-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-xmlada-25

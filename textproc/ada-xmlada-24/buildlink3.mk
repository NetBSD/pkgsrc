# $NetBSD: buildlink3.mk,v 1.1 2025/07/10 10:50:23 dkazankov Exp $

BUILDLINK_TREE+=	xmlada-24

.if !defined(XMLADA_24_BUILDLINK3_MK)
XMLADA_24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlada-24+=	xmlada-${GNAT_NAME}>=24.0.0
BUILDLINK_PKGSRCDIR.xmlada-24?=		../../textproc/ada-xmlada-24
BUILDLINK_DEPMETHOD.xmlada-24?=		build

BUILDLINK_CONTENTS_FILTER.xmlada-24=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.xmlada-24+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-xmlada-24

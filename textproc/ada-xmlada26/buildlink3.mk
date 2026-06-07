# $NetBSD: buildlink3.mk,v 1.1 2026/06/07 03:38:56 dkazankov Exp $

BUILDLINK_TREE+=	ada-xmlada26

.if !defined(ADA_XMLADA26_BUILDLINK3_MK)
ADA_XMLADA26_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ada-xmlada26+=	ada-xmlada-${GNAT_NAME}>=26.0.0
BUILDLINK_PKGSRCDIR.ada-xmlada26?=	../../textproc/ada-xmlada26
BUILDLINK_DEPMETHOD.ada-xmlada26?=	build

BUILDLINK_CONTENTS_FILTER.ada-xmlada26=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.ada-xmlada26+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-ada-xmlada26

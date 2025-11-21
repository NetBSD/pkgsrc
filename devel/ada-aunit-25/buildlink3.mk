# $NetBSD: buildlink3.mk,v 1.1 2025/11/21 14:55:29 dkazankov Exp $

BUILDLINK_TREE+=	aunit-25

.if !defined(AUNIT_25_BUILDLINK3_MK)
AUNIT_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aunit-25+=	aunit>=25.0.0
BUILDLINK_PKGSRCDIR.aunit-25?=		../../devel/ada-aunit-25
BUILDLINK_DEPMETHOD.aunit-25?=		build

BUILDLINK_CONTENTS_FILTER.aunit-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.aunit-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-aunit-25

# $NetBSD: buildlink3.mk,v 1.1 2025/11/28 20:35:15 dkazankov Exp $

BUILDLINK_TREE+=	ada-gnat_util14

.if !defined(ADA_GNAT_UTIL14_BUILDLINK3_MK)
ADA_GNAT_UTIL14_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ada-gnat_util14+=	ada-gnat_util14>=14.3.0
BUILDLINK_PKGSRCDIR.ada-gnat_util14?=	../../devel/ada-gnat_util14
BUILDLINK_DEPMETHOD.ada-gnat_util14?=	build

BUILDLINK_CONTENTS_FILTER.ada-gnat_util14=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.ada-gnat_util14+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-ada-gnat_util14

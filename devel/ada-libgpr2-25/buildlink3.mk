# $NetBSD: buildlink3.mk,v 1.1 2025/07/28 05:46:26 dkazankov Exp $

BUILDLINK_TREE+=	libgpr2-25

.if !defined(LIBGPR2_25_BUILDLINK3_MK)
LIBGPR2_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpr2-25+=	libgpr2-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.libgpr2-25?=	../../devel/ada-libgpr2-25
BUILDLINK_DEPMETHOD.libgpr2-25?=	build

BUILDLINK_CONTENTS_FILTER.libgpr2-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libgpr2-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-libgpr2-25

# $NetBSD: buildlink3.mk,v 1.2 2025/07/10 15:30:50 dkazankov Exp $

BUILDLINK_TREE+=	libgpr-24

.if !defined(LIBGPR_24_BUILDLINK3_MK)
LIBGPR_24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpr-24+=	libgpr-${GNAT_NAME}>=24.0.0
BUILDLINK_PKGSRCDIR.libgpr-24?=		../../devel/ada-libgpr-24
BUILDLINK_DEPMETHOD.libgpr-24?=		build

BUILDLINK_CONTENTS_FILTER.libgpr-24=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libgpr-24+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-libgpr-24

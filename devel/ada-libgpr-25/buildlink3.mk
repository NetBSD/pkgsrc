# $NetBSD: buildlink3.mk,v 1.2 2025/10/09 16:19:32 dkazankov Exp $

BUILDLINK_TREE+=	libgpr-25

.if !defined(LIBGPR_25_BUILDLINK3_MK)
LIBGPR_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpr-25+=	libgpr-${GNAT_NAME}>=25.0.0
BUILDLINK_ABI_DEPENDS.libgpr-25+=	libgpr-${GNAT_NAME}>=25.2.0
BUILDLINK_PKGSRCDIR.libgpr-25?=		../../devel/ada-libgpr-25
BUILDLINK_DEPMETHOD.libgpr-25?=		build

BUILDLINK_CONTENTS_FILTER.libgpr-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libgpr-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"

.endif

BUILDLINK_TREE+=	-libgpr-25

# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 07:48:28 dkazankov Exp $

BUILDLINK_TREE+=	libgnatformat-25

.if !defined(LIBGNATFORMAT_25_BUILDLINK3_MK)
LIBGNATFORMAT_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnatformat-25+=	libgnatformat-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.libgnatformat-25?=		../../textproc/ada-libgnatformat-25
BUILDLINK_DEPMETHOD.libgnatformat-25?=		build

BUILDLINK_CONTENTS_FILTER.libgnatformat-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libgnatformat-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-libgnatformat-25

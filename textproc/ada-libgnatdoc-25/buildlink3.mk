# $NetBSD: buildlink3.mk,v 1.1 2025/09/07 08:02:41 dkazankov Exp $

BUILDLINK_TREE+=	libgnatdoc-25

.if !defined(LIBGNATDOC_25_BUILDLINK3_MK)
LIBGNATDOC_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnatdoc-25+=	libgnatdoc-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.libgnatdoc-25?=	../../textproc/ada-libgnatdoc-25
BUILDLINK_DEPMETHOD.libgnatdoc-25?=	build

BUILDLINK_CONTENTS_FILTER.libgnatdoc-25=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.libgnatdoc-25+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-libgnatdoc-25

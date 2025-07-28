# $NetBSD: buildlink3.mk,v 1.1 2025/07/28 11:34:51 dkazankov Exp $

BUILDLINK_TREE+=	vss-25

.if !defined(VSS_25_BUILDLINK3_MK)
VSS_25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vss-25+=		vss-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.vss-25?=		../../textproc/ada-vss-25
BUILDLINK_DEPMETHOD.vss-25?=		build

BUILDLINK_FILES.ada-vss+=		include/vss/*/*/* lib/libvss* lib/vss/*/*/*
BUILDLINK_FILES.ada-vss+=		share/gpr/manifests/vss_* share/gpr/vss_*.gpr

BUILDLINK_CONTENTS_FILTER.vss-25=	\
    ${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.vss-25+=	\
    -e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-vss-25

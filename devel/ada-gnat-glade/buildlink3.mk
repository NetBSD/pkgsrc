# $NetBSD: buildlink3.mk,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

BUILDLINK_TREE+=	gnat-glade

.if !defined(GNAT_GLADE_BUILDLINK3_MK)
GNAT_GLADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnat-glade+=	gnat-glade-${GNAT_NAME}>=6.0.1
BUILDLINK_PKGSRCDIR.gnat-glade?=	../../devel/ada-gnat-glade
BUILDLINK_DEPMETHOD.gnat-glade?=	build

BUILDLINK_CONTENTS_FILTER.gnat-glade=	\
	${EGREP} "${GNAT_PKGBASE}/bin/.*$$|${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$"

BUILDLINK_FNAME_TRANSFORM.gnat-glade+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-gnat-glade

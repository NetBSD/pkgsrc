# $NetBSD: buildlink3.mk,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

BUILDLINK_TREE+=	polyorb

.if !defined(POLYORB_BUILDLINK3_MK)
POLYORB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyorb+=	polyorb-${GNAT_NAME}>=25.0.0
BUILDLINK_PKGSRCDIR.polyorb?=	../../net/ada-polyorb
BUILDLINK_DEPMETHOD.polyorb?=	build

BUILDLINK_CONTENTS_FILTER.polyorb=	\
	${EGREP} "${GNAT_PKGBASE}/include/.*$$|${GNAT_PKGBASE}/lib/.*$$|${GNAT_PKGBASE}/share/gpr/.*$$"

BUILDLINK_FNAME_TRANSFORM.polyorb+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

pkgbase := polyorb
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-polyorb

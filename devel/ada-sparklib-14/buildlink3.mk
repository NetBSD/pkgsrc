# $NetBSD: buildlink3.mk,v 1.2 2025/09/09 09:15:52 dkazankov Exp $

BUILDLINK_TREE+=	sparklib-14

.if !defined(SPARKLIB_14_BUILDLINK3_MK)
SPARKLIB_14_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sparklib-14+=	sparklib14>=14.0.0
BUILDLINK_PKGSRCDIR.sparklib-14?=	../../devel/ada-sparklib-14
BUILDLINK_DEPMETHOD.sparklib-14?=	build

BUILDLINK_CONTENTS_FILTER.sparklib-14=	${TRUE}

BUILDLINK_FNAME_TRANSFORM.sparklib-14+=	\
	-e "s|${BUILDLINK_DIR}/${GNAT_PKGBASE}/|${BUILDLINK_DIR}/|g"

.endif

BUILDLINK_TREE+=	-sparklib-14

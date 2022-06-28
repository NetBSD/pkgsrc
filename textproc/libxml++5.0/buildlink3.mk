# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:36:12 wiz Exp $

BUILDLINK_TREE+=	libxmlpp5.0

.if !defined(LIBXMLPP5.0_BUILDLINK3_MK)
LIBXMLPP5.0_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlpp5.0+=	libxml++>=5.0.1
BUILDLINK_ABI_DEPENDS.libxmlpp5.0?=	libxml++5.0>=5.0.1nb3
BUILDLINK_PKGSRCDIR.libxmlpp5.0?=	../../textproc/libxml++5.0

.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBXMLPP5.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlpp5.0

# $NetBSD: buildlink3.mk,v 1.18 2022/06/28 11:36:12 wiz Exp $

BUILDLINK_TREE+=	libxmlpp

.if !defined(LIBXMLPP_BUILDLINK3_MK)
LIBXMLPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlpp+=	libxml++>=2.10.0
BUILDLINK_ABI_DEPENDS.libxmlpp+=	libxml++>=2.40.1nb12
BUILDLINK_PKGSRCDIR.libxmlpp?=		../../textproc/libxml++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.endif # LIBXMLPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlpp

# $NetBSD: buildlink3.mk,v 1.14 2020/11/05 09:07:10 ryoon Exp $

BUILDLINK_TREE+=	libxmlpp

.if !defined(LIBXMLPP_BUILDLINK3_MK)
LIBXMLPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlpp+=	libxml++>=2.10.0
BUILDLINK_ABI_DEPENDS.libxmlpp+=	libxml++>=2.40.1nb7
BUILDLINK_PKGSRCDIR.libxmlpp?=		../../textproc/libxml++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.endif # LIBXMLPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlpp

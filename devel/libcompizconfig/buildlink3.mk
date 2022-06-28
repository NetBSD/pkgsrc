# $NetBSD: buildlink3.mk,v 1.14 2022/06/28 11:31:46 wiz Exp $

BUILDLINK_TREE+=	libcompizconfig

.if !defined(LIBCOMPIZCONFIG_BUILDLINK3_MK)
LIBCOMPIZCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcompizconfig+=	libcompizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.libcompizconfig+=	libcompizconfig>=0.8.8nb59
BUILDLINK_PKGSRCDIR.libcompizconfig?=	../../devel/libcompizconfig

.include "../../devel/protobuf/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBCOMPIZCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcompizconfig

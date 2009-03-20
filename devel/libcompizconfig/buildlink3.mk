# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libcompizconfig

.if !defined(LIBCOMPIZCONFIG_BUILDLINK3_MK)
LIBCOMPIZCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcompizconfig+=	libcompizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.libcompizconfig?=	libcompizconfig>=0.6.0
BUILDLINK_PKGSRCDIR.libcompizconfig?=	../../devel/libcompizconfig

.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBCOMPIZCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcompizconfig

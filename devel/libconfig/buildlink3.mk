# $NetBSD: buildlink3.mk,v 1.3 2013/10/30 21:15:49 gls Exp $

BUILDLINK_TREE+=	libconfig

.if !defined(LIBCONFIG_BUILDLINK3_MK)
LIBCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libconfig+=	libconfig>=1.4
BUILDLINK_PKGSRCDIR.libconfig?=		../../devel/libconfig
.endif # LIBCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libconfig

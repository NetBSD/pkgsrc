# $NetBSD: buildlink3.mk,v 1.1 2014/01/10 22:30:36 cheusov Exp $

BUILDLINK_TREE+=	libdshconfig

.if !defined(LIBDSHCONFIG_BUILDLINK3_MK)
LIBDSHCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdshconfig+=	libdshconfig>=0.20.13
BUILDLINK_PKGSRCDIR.libdshconfig?=	../../devel/libdshconfig
.endif	# LIBDSHCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdshconfig

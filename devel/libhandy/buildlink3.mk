# $NetBSD: buildlink3.mk,v 1.12 2023/08/14 05:24:11 wiz Exp $

BUILDLINK_TREE+=	libhandy

.if !defined(LIBHANDY_BUILDLINK3_MK)
LIBHANDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhandy+=	libhandy>=0.0.13
BUILDLINK_ABI_DEPENDS.libhandy?=	libhandy>=1.8.0nb4
BUILDLINK_PKGSRCDIR.libhandy?=		../../devel/libhandy
BUILDLINK_INCDIRS.libhandy+=		include/libhandy-0.0

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBHANDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhandy

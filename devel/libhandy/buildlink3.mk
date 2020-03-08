# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:38 wiz Exp $

BUILDLINK_TREE+=	libhandy

.if !defined(LIBHANDY_BUILDLINK3_MK)
LIBHANDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhandy+=	libhandy>=0.0.13
BUILDLINK_ABI_DEPENDS.libhandy?=		libhandy>=0.0.13nb1
BUILDLINK_PKGSRCDIR.libhandy?=		../../devel/libhandy
BUILDLINK_INCDIRS.libhandy+=		include/libhandy-0.0

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBHANDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhandy

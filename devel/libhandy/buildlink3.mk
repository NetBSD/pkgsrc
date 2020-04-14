# $NetBSD: buildlink3.mk,v 1.4 2020/04/14 20:28:38 prlw1 Exp $

BUILDLINK_TREE+=	libhandy

.if !defined(LIBHANDY_BUILDLINK3_MK)
LIBHANDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhandy+=	libhandy>=0.0.13
BUILDLINK_ABI_DEPENDS.libhandy?=	libhandy>=0.0.13nb2
BUILDLINK_PKGSRCDIR.libhandy?=		../../devel/libhandy
BUILDLINK_INCDIRS.libhandy+=		include/libhandy-0.0

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBHANDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhandy

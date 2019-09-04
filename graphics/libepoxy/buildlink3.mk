# $NetBSD: buildlink3.mk,v 1.3 2019/09/04 16:38:06 nia Exp $

BUILDLINK_TREE+=	libepoxy

.if !defined(LIBEPOXY_BUILDLINK3_MK)
LIBEPOXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.2
BUILDLINK_PKGSRCDIR.libepoxy?=		../../graphics/libepoxy

.include "../../graphics/MesaLib/buildlink3.mk"
.endif	# LIBEPOXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoxy

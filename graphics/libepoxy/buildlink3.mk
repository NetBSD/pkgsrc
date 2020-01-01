# $NetBSD: buildlink3.mk,v 1.4 2020/01/01 21:16:12 adam Exp $

BUILDLINK_TREE+=	libepoxy

.if !defined(LIBEPOXY_BUILDLINK3_MK)
LIBEPOXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.2
BUILDLINK_PKGSRCDIR.libepoxy?=		../../graphics/libepoxy

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.endif	# LIBEPOXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoxy

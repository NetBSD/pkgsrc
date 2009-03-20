# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:47 joerg Exp $

BUILDLINK_TREE+=	libtabe

.if !defined(LIBTABE_BUILDLINK3_MK)
LIBTABE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtabe+=	libtabe>=0.2.5
BUILDLINK_ABI_DEPENDS.libtabe+=	libtabe>=0.2.5nb2
BUILDLINK_PKGSRCDIR.libtabe?=	../../inputmethod/libtabe

.include "../../databases/db3/buildlink3.mk"
.endif # LIBTABE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtabe

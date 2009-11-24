# $NetBSD: buildlink3.mk,v 1.9 2009/11/24 11:15:14 obache Exp $

BUILDLINK_TREE+=	libtabe

.if !defined(LIBTABE_BUILDLINK3_MK)
LIBTABE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtabe+=	libtabe>=0.2.5
BUILDLINK_ABI_DEPENDS.libtabe+=	libtabe>=0.2.6
BUILDLINK_PKGSRCDIR.libtabe?=	../../inputmethod/libtabe

.include "../../mk/bdb.buildlink3.mk"
.endif # LIBTABE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtabe

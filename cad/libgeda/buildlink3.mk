# $NetBSD: buildlink3.mk,v 1.28 2009/08/26 19:56:51 sno Exp $

BUILDLINK_TREE+=	libgeda

.if !defined(LIBGEDA_BUILDLINK3_MK)
LIBGEDA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgeda+=	libgeda-1.4.3{,nb[0-9]*}
BUILDLINK_ABI_DEPENDS.libgeda?=	libgeda>=1.4.3nb1
BUILDLINK_PKGSRCDIR.libgeda?=	../../cad/libgeda

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGEDA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgeda

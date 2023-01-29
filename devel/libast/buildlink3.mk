# $NetBSD: buildlink3.mk,v 1.25 2023/01/29 21:14:29 ryoon Exp $

BUILDLINK_TREE+=	libast

.if !defined(LIBAST_BUILDLINK3_MK)
LIBAST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libast+=	libast>=0.5nb5
BUILDLINK_ABI_DEPENDS.libast+=	libast>=0.7nb13
BUILDLINK_PKGSRCDIR.libast?=	../../devel/libast

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBAST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libast

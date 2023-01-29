# $NetBSD: buildlink3.mk,v 1.25 2023/01/29 21:14:31 ryoon Exp $

BUILDLINK_TREE+=	libmatchbox

.if !defined(LIBMATCHBOX_BUILDLINK3_MK)
LIBMATCHBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatchbox+=	libmatchbox>=1.4
BUILDLINK_ABI_DEPENDS.libmatchbox+=	libmatchbox>=1.9nb12
BUILDLINK_PKGSRCDIR.libmatchbox?=	../../devel/libmatchbox

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # LIBMATCHBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatchbox

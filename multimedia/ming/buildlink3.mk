# $NetBSD: buildlink3.mk,v 1.10 2011/01/13 13:36:13 wiz Exp $

BUILDLINK_TREE+=	ming

.if !defined(MING_BUILDLINK3_MK)
MING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ming+=	ming>=0.4.3
BUILDLINK_ABI_DEPENDS.ming?=	ming>=0.4.3nb2
BUILDLINK_PKGSRCDIR.ming?=	../../multimedia/ming

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # MING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ming

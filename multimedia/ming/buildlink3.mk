# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:04 joerg Exp $

BUILDLINK_TREE+=	ming

.if !defined(MING_BUILDLINK3_MK)
MING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ming+=	ming>=0.3.0
BUILDLINK_PKGSRCDIR.ming?=	../../multimedia/ming

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # MING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ming

# $NetBSD: buildlink3.mk,v 1.17 2013/07/05 13:29:41 ryoon Exp $

BUILDLINK_TREE+=	ming

.if !defined(MING_BUILDLINK3_MK)
MING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ming+=	ming>=0.4.3
BUILDLINK_ABI_DEPENDS.ming+=	ming>=0.4.5nb1
BUILDLINK_PKGSRCDIR.ming?=	../../multimedia/ming

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # MING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ming

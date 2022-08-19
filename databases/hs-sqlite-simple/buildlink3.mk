# $NetBSD: buildlink3.mk,v 1.3 2022/08/19 11:43:50 tnn Exp $

BUILDLINK_TREE+=	hs-sqlite-simple

.if !defined(HS_SQLITE_SIMPLE_BUILDLINK3_MK)
HS_SQLITE_SIMPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-sqlite-simple+=	hs-sqlite-simple>=0.4.18
BUILDLINK_ABI_DEPENDS.hs-sqlite-simple+=	hs-sqlite-simple>=0.4.18.0nb1
BUILDLINK_PKGSRCDIR.hs-sqlite-simple?=		../../databases/hs-sqlite-simple

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-blaze-textual/buildlink3.mk"
.include "../../databases/hs-direct-sqlite/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/hs-Only/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_SQLITE_SIMPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-sqlite-simple

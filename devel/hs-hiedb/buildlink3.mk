# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:15 wiz Exp $

BUILDLINK_TREE+=	hs-hiedb

.if !defined(HS_HIEDB_BUILDLINK3_MK)
HS_HIEDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hiedb+=	hs-hiedb>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-hiedb+=	hs-hiedb>=0.4.1.0nb3
BUILDLINK_PKGSRCDIR.hs-hiedb?=		../../devel/hs-hiedb

.include "../../math/hs-algebraic-graphs/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../textproc/hs-lucid/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.endif	# HS_HIEDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hiedb

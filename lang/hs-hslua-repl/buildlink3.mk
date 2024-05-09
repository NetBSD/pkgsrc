# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:32:23 pho Exp $

BUILDLINK_TREE+=	hs-hslua-repl

.if !defined(HS_HSLUA_REPL_BUILDLINK3_MK)
HS_HSLUA_REPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-repl+=	hs-hslua-repl>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-hslua-repl+=	hs-hslua-repl>=0.1.2nb1
BUILDLINK_PKGSRCDIR.hs-hslua-repl?=	../../lang/hs-hslua-repl

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../devel/hs-isocline/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_HSLUA_REPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-repl

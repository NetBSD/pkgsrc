# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:43 dholland Exp $

BUILDLINK_TREE+=	swi-prolog-lite

.if !defined(SWI_PROLOG_LITE_BUILDLINK3_MK)
SWI_PROLOG_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swi-prolog-lite+=	swi-prolog-lite>=5.2.9
BUILDLINK_ABI_DEPENDS.swi-prolog-lite+=	swi-prolog-lite>=5.9.7nb1
BUILDLINK_PKGSRCDIR.swi-prolog-lite?=	../../lang/swi-prolog-lite

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../devel/gmp/buildlink3.mk" ?
.endif	# SWI_PROLOG_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-swi-prolog-lite

# $NetBSD: buildlink3.mk,v 1.14 2019/02/25 15:20:44 leot Exp $

BUILDLINK_TREE+=	swi-prolog-lite

.if !defined(SWI_PROLOG_LITE_BUILDLINK3_MK)
SWI_PROLOG_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swi-prolog-lite+=	swi-prolog-lite>=8.0.1
BUILDLINK_PKGSRCDIR.swi-prolog-lite?=	../../lang/swi-prolog-lite

.endif	# SWI_PROLOG_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-swi-prolog-lite

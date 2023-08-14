# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:09 wiz Exp $

BUILDLINK_TREE+=	cracklib

.if !defined(CRACKLIB_BUILDLINK3_MK)
CRACKLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cracklib+=	cracklib>=2.9.7
BUILDLINK_ABI_DEPENDS.cracklib?=		cracklib>=2.9.7nb1
BUILDLINK_PKGSRCDIR.cracklib?=		../../security/cracklib
.endif	# CRACKLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cracklib

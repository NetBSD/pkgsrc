# $NetBSD: buildlink3.mk,v 1.1 2020/11/22 11:36:31 nia Exp $

BUILDLINK_TREE+=	cracklib

.if !defined(CRACKLIB_BUILDLINK3_MK)
CRACKLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cracklib+=	cracklib>=2.9.7
BUILDLINK_PKGSRCDIR.cracklib?=		../../security/cracklib
.endif	# CRACKLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cracklib

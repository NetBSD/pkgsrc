# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 20:25:35 markd Exp $

BUILDLINK_TREE+=	kdemultimedia4

.if !defined(KDEMULTIMEDIA4_BUILDLINK3_MK)
KDEMULTIMEDIA4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdemultimedia4+=	kdemultimedia4>=4.1.0
BUILDLINK_PKGSRCDIR.kdemultimedia4?=	../../multimedia/kdemultimedia4

.endif # KDEMULTIMEDIA4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdemultimedia4

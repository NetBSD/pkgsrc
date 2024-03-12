# $NetBSD: buildlink3.mk,v 1.1 2024/03/12 17:53:15 wiz Exp $

BUILDLINK_TREE+=	alire

.if !defined(ALIRE_BUILDLINK3_MK)
ALIRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alire+=	alire>=2.0.0rc1
BUILDLINK_PKGSRCDIR.alire=	../../devel/alire
BUILDLINK_DEPMETHOD.alire?=	build

.endif

BUILDLINK_TREE+=	-alire

# $NetBSD: buildlink3.mk,v 1.1 2024/03/14 19:20:29 markd Exp $

BUILDLINK_TREE+=	lager

.if !defined(LAGER_BUILDLINK3_MK)
LAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lager+=	lager>=0.1.1
BUILDLINK_DEPMETHOD.lager?=	build
BUILDLINK_PKGSRCDIR.lager?=	../../devel/lager
.endif	# LAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-lager

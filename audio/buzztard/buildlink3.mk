# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:03:54 rillig Exp $

BUILDLINK_TREE+=	buzztard

.if !defined(BUZZTARD_BUILDLINK3_MK)
BUZZTARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.buzztard+=	buzztard>=0.5.0
BUILDLINK_PKGSRCDIR.buzztard?=		../../audio/buzztard

.endif	# BUZZTARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-buzztard

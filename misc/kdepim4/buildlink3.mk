# $NetBSD: buildlink3.mk,v 1.1 2010/01/17 11:24:04 markd Exp $

BUILDLINK_TREE+=	kdepim4

.if !defined(KDEPIM4_BUILDLINK3_MK)
KDEPIM4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim4+=	kdepim4>=4.3.4
BUILDLINK_PKGSRCDIR.kdepim4?=	../../misc/kdepim4

.endif	# KDEPIM4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim4

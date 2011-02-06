# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/06 19:46:48 schnoebe Exp $

BUILDLINK_TREE+=	gloox

.if !defined(GLOOX_BUILDLINK3_MK)
GLOOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gloox+=	gloox>=1.0
BUILDLINK_PKGSRCDIR.gloox?=	../../chat/gloox

.endif # GLOOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gloox

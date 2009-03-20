# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:40 joerg Exp $

BUILDLINK_TREE+=	Hermes

.if !defined(HERMES_BUILDLINK3_MK)
HERMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Hermes+=	Hermes>=1.3.2
BUILDLINK_ABI_DEPENDS.Hermes+=	Hermes>=1.3.3nb2
BUILDLINK_PKGSRCDIR.Hermes?=	../../graphics/hermes
.endif # HERMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Hermes

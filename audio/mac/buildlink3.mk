# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:57 joerg Exp $

BUILDLINK_TREE+=	mac

.if !defined(MAC_BUILDLINK3_MK)
MAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mac+=	mac>=3.99u4b5
BUILDLINK_PKGSRCDIR.mac?=	../../audio/mac
.endif # MAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mac

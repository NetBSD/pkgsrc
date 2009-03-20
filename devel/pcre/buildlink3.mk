# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:26 joerg Exp $

BUILDLINK_TREE+=	pcre

.if !defined(PCRE_BUILDLINK3_MK)
PCRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcre+=	pcre>=3.4nb1
BUILDLINK_ABI_DEPENDS.pcre+=	pcre>=6.2
BUILDLINK_PKGSRCDIR.pcre?=	../../devel/pcre
.endif # PCRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcre

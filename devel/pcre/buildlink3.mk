# $NetBSD: buildlink3.mk,v 1.12 2012/03/03 00:11:52 wiz Exp $

BUILDLINK_TREE+=	pcre

.if !defined(PCRE_BUILDLINK3_MK)
PCRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcre+=	pcre>=3.4nb1
BUILDLINK_ABI_DEPENDS.pcre+=	pcre>=8.30nb1
BUILDLINK_PKGSRCDIR.pcre?=	../../devel/pcre
.endif # PCRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcre

# $NetBSD: buildlink3.mk,v 1.8 2012/03/03 00:11:52 wiz Exp $

BUILDLINK_TREE+=	pcrexx

.if !defined(PCREXX_BUILDLINK3_MK)
PCREXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcrexx+=	pcre++>=0.9.5
BUILDLINK_ABI_DEPENDS.pcrexx?=	pcre++>=0.9.5nb2
BUILDLINK_PKGSRCDIR.pcrexx?=	../../devel/pcre++

.include "../../devel/pcre/buildlink3.mk"
.endif # PCREXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcrexx

# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:26 joerg Exp $

BUILDLINK_TREE+=	pcrexx

.if !defined(PCREXX_BUILDLINK3_MK)
PCREXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcrexx+=	pcre++>=0.9.5
BUILDLINK_PKGSRCDIR.pcrexx?=	../../devel/pcre++

.include "../../devel/pcre/buildlink3.mk"
.endif # PCREXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcrexx

# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	mecab

.if !defined(MECAB_BUILDLINK3_MK)
MECAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mecab+=	mecab>=0.90
BUILDLINK_PKGSRCDIR.mecab?=	../../textproc/mecab

.include "../../textproc/mecab-base/buildlink3.mk"
.endif # MECAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-mecab

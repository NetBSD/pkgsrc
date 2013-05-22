# $NetBSD: buildlink3.mk,v 1.2 2013/05/22 13:14:29 obache Exp $

BUILDLINK_TREE+=	cabocha

.if !defined(CABOCHA_BUILDLINK3_MK)
CABOCHA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=0.66
BUILDLINK_PKGSRCDIR.cabocha?=	../../textproc/cabocha

.include "../../textproc/CRF++/buildlink3.mk"
.include "../../textproc/mecab/buildlink3.mk"
.endif	# CABOCHA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabocha

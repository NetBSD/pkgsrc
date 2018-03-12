# $NetBSD: buildlink3.mk,v 1.2 2018/03/12 11:15:46 wiz Exp $

BUILDLINK_TREE+=	WordNet

.if !defined(WORDNET_BUILDLINK3_MK)
WORDNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.WordNet+=	WordNet>=3.0nb7
BUILDLINK_ABI_DEPENDS.WordNet?=	WordNet>=3.0nb8
BUILDLINK_PKGSRCDIR.WordNet?=	../../textproc/WordNet

.include "../../x11/tk/buildlink3.mk"
.endif	# WORDNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-WordNet

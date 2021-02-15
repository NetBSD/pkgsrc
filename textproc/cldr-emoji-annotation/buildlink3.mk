# $NetBSD: buildlink3.mk,v 1.1 2021/02/15 15:01:35 ryoon Exp $

BUILDLINK_TREE+=	cldr-emoji-annotation

.if !defined(CLDR_EMOJI_ANNOTATION_BUILDLINK3_MK)
CLDR_EMOJI_ANNOTATION_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cldr-emoji-annotation?=	build

BUILDLINK_API_DEPENDS.cldr-emoji-annotation+=	cldr-emoji-annotation>=37.0.13.0.0.2
BUILDLINK_PKGSRCDIR.cldr-emoji-annotation?=	../../textproc/cldr-emoji-annotation
.endif	# CLDR_EMOJI_ANNOTATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-cldr-emoji-annotation

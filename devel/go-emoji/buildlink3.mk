# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-emoji

.if !defined(GO_EMOJI_BUILDLINK3_MK)
GO_EMOJI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-emoji=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-emoji?=		build

BUILDLINK_API_DEPENDS.go-emoji+=	go-emoji>=1.4
BUILDLINK_PKGSRCDIR.go-emoji?=		../../devel/go-emoji

.endif  # GO_EMOJI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-emoji

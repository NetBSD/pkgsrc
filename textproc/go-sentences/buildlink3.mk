# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:15 jperkin Exp $

BUILDLINK_TREE+=	go-sentences

.if !defined(GO_SENTENCES_BUILDLINK3_MK)
GO_SENTENCES_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sentences=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sentences?=		build

BUILDLINK_API_DEPENDS.go-sentences+=		go-sentences>=1.0.6
BUILDLINK_PKGSRCDIR.go-sentences?=		../../textproc/go-sentences

.endif  # GO_SENTENCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sentences

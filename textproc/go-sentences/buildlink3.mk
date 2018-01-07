# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:33 rillig Exp $

BUILDLINK_TREE+=	go-sentences

.if !defined(GO_SENTENCES_BUILDLINK3_MK)
GO_SENTENCES_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sentences=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sentences?=	build

BUILDLINK_API_DEPENDS.go-sentences+=		go-sentences>=1.0.6
BUILDLINK_PKGSRCDIR.go-sentences?=		../../textproc/go-sentences

.endif  # GO_SENTENCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sentences

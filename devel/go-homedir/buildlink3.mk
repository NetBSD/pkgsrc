# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:28:52 gavan Exp $

BUILDLINK_TREE+=	go-homedir

.if !defined(GO_HOMEDIR_BUILDLINK3_MK)
GO_HOMEDIR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-homedir=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-homedir?=		build

BUILDLINK_API_DEPENDS.go-homedir+=		go-homedir>=0.0
BUILDLINK_PKGSRCDIR.go-homedir?=		../../devel/go-homedir

.endif  # GO_HOMEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-homedir


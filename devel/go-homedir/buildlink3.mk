# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-homedir

.if !defined(GO_HOMEDIR_BUILDLINK3_MK)
GO_HOMEDIR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-homedir=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-homedir?=		build

BUILDLINK_API_DEPENDS.go-homedir+=		go-homedir>=0.0
BUILDLINK_PKGSRCDIR.go-homedir?=		../../devel/go-homedir

.endif  # GO_HOMEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-homedir

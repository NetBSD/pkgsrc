# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-fs

.if !defined(GO_FS_BUILDLINK3_MK)
GO_FS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fs?=		build

BUILDLINK_API_DEPENDS.go-fs+=		go-fs>=0.0
BUILDLINK_PKGSRCDIR.go-fs?=		../../devel/go-fs

.endif  # GO_FS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fs

# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:23:52 gavan Exp $

BUILDLINK_TREE+=	go-fs

.if !defined(GO_FS_BUILDLINK3_MK)
GO_FS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fs?=		build

BUILDLINK_API_DEPENDS.go-fs+=		go-fs>=0.0
BUILDLINK_PKGSRCDIR.go-fs?=		../../devel/go-fs

.endif  # GO_FS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fs


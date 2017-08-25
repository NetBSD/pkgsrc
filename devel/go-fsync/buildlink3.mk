# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-fsync

.if !defined(GO_FSYNC_BUILDLINK3_MK)
GO_FSYNC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fsync=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fsync?=		build

BUILDLINK_API_DEPENDS.go-fsync+=	go-fsync>=0.0
BUILDLINK_PKGSRCDIR.go-fsync?=		../../devel/go-fsync

.include "../../devel/go-afero/buildlink3.mk"
.endif  # GO_FSYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fsync

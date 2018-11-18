# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:17:22 ryoon Exp $

BUILDLINK_TREE+=	go-locker

.if !defined(GO_LOCKER_BUILDLINK3_MK)
GO_LOCKER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-locker=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-locker?=		build

BUILDLINK_API_DEPENDS.go-locker+=	go-locker>=0.0.0.20171007
BUILDLINK_PKGSRCDIR.go-locker?=		../../devel/go-locker
.endif	# GO_LOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-locker

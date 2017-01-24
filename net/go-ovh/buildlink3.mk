# $NetBSD: buildlink3.mk,v 1.1 2017/01/24 17:22:09 bsiegert Exp $

BUILDLINK_TREE+=	go-ovh

.if !defined(GO_OVH_BUILDLINK3_MK)
GO_OVH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ovh=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ovh?=		build

BUILDLINK_API_DEPENDS.go-ovh+=	go-ovh>=0.20170102
BUILDLINK_PKGSRCDIR.go-ovh?=	../../net/go-ovh

.include "../../devel/go-ini/buildlink3.mk"
.endif	# GO_OVH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ovh

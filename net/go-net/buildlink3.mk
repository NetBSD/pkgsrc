# $NetBSD: buildlink3.mk,v 1.2 2015/12/29 21:47:48 bsiegert Exp $

BUILDLINK_TREE+=	go-net

.if !defined(GO_NET_BUILDLINK3_MK)
GO_NET_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-net= ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-net?=	build

BUILDLINK_API_DEPENDS.go-net+=	go-net>=20150310
BUILDLINK_PKGSRCDIR.go-net?=	../../net/go-net

.include "../../textproc/go-text/buildlink3.mk"
.endif	# GO_NET_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-net

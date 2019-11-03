# $NetBSD: buildlink3.mk,v 1.6 2019/11/03 11:45:35 rillig Exp $

BUILDLINK_TREE+=	go-net

.if !defined(GO_NET_BUILDLINK3_MK)
GO_NET_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-net=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-net?=		build

BUILDLINK_API_DEPENDS.go-net+=	go-net>=20170308
BUILDLINK_PKGSRCDIR.go-net?=	../../net/go-net

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.endif	# GO_NET_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-net

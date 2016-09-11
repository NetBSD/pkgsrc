# $NetBSD: buildlink3.mk,v 1.4 2016/09/11 08:25:40 bsiegert Exp $

BUILDLINK_TREE+=	go-net

.if !defined(GO_NET_BUILDLINK3_MK)
GO_NET_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-net= ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-net?=	build

BUILDLINK_API_DEPENDS.go-net+=	go-net>=20160910
BUILDLINK_PKGSRCDIR.go-net?=	../../net/go-net

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.endif	# GO_NET_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-net

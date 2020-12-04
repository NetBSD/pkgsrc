# $NetBSD: buildlink3.mk,v 1.1 2020/12/04 09:25:33 bsiegert Exp $

BUILDLINK_TREE+=	go-mod

.if !defined(GO_MOD_BUILDLINK3_MK)
GO_MOD_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mod=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mod?=		build

BUILDLINK_API_DEPENDS.go-mod+=	go-mod>=0.4.0
BUILDLINK_PKGSRCDIR.go-mod?=	../../devel/go-mod

.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.endif	# GO_MOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mod

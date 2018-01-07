# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:02 rillig Exp $

BUILDLINK_TREE+=	go-jwalterweatherman

.if !defined(GO_JWALTERWEATHERMAN_BUILDLINK3_MK)
GO_JWALTERWEATHERMAN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jwalterweatherman=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jwalterweatherman?=	build

BUILDLINK_API_DEPENDS.go-jwalterweatherman+=		go-jWalterWeatherman>=20170523
BUILDLINK_PKGSRCDIR.go-jwalterweatherman?=		../../devel/go-jwalterweatherman

.endif  # GO_JWALTERWEATHERMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jwalterweatherman

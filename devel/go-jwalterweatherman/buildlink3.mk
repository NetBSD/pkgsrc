# $NetBSD: buildlink3.mk,v 1.4 2018/11/18 08:11:07 ryoon Exp $

BUILDLINK_TREE+=	go-jwalterweatherman

.if !defined(GO_JWALTERWEATHERMAN_BUILDLINK3_MK)
GO_JWALTERWEATHERMAN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jwalterweatherman=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jwalterweatherman?=	build

BUILDLINK_API_DEPENDS.go-jwalterweatherman+=		go-jwalterweatherman>=20181028
BUILDLINK_PKGSRCDIR.go-jwalterweatherman?=		../../devel/go-jwalterweatherman

.endif  # GO_JWALTERWEATHERMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jwalterweatherman

# $NetBSD: buildlink3.mk,v 1.1 2018/09/11 00:08:46 minskim Exp $

BUILDLINK_TREE+=	go-godotenv

.if !defined(GO_GODOTENV_BUILDLINK3_MK)
GO_GODOTENV_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-godotenv=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-godotenv?=	build

BUILDLINK_API_DEPENDS.go-godotenv+=	go-godotenv>=1.2.0
BUILDLINK_PKGSRCDIR.go-godotenv?=	../../devel/go-godotenv
.endif	# GO_GODOTENV_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-godotenv

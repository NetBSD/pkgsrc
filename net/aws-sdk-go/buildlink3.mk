# $NetBSD: buildlink3.mk,v 1.1 2016/08/21 19:54:07 bsiegert Exp $

BUILDLINK_TREE+=	aws-sdk-go

.if !defined(AWS_SDK_GO_BUILDLINK3_MK)
AWS_SDK_GO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.aws-sdk-go=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.aws-sdk-go?=		build

BUILDLINK_API_DEPENDS.aws-sdk-go+=	aws-sdk-go>=1.4.3
BUILDLINK_PKGSRCDIR.aws-sdk-go?=	../../net/go-aws-sdk

.endif	# AWS_SDK_GO_BUILDLINK3_MK

BUILDLINK_TREE+=	-aws-sdk-go

# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-sftp

.if !defined(GO_SFTP_BUILDLINK3_MK)
GO_SFTP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sftp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sftp?=		build

BUILDLINK_API_DEPENDS.go-sftp+=		go-sftp>=0.0
BUILDLINK_PKGSRCDIR.go-sftp?=		../../security/go-sftp

.endif  # GO_SFTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sftp

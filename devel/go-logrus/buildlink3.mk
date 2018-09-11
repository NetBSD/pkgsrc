# $NetBSD: buildlink3.mk,v 1.1 2018/09/11 17:45:06 minskim Exp $

BUILDLINK_TREE+=	go-logrus

.if !defined(GO_LOGRUS_BUILDLINK3_MK)
GO_LOGRUS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-logrus=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-logrus?=		build

BUILDLINK_API_DEPENDS.go-logrus+=	go-logrus>=1.0.6
BUILDLINK_PKGSRCDIR.go-logrus?=		../../devel/go-logrus

.include "../../devel/go-sys/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.endif	# GO_LOGRUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-logrus

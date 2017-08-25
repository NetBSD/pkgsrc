# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-cobra

.if !defined(GO_COBRA_BUILDLINK3_MK)
GO_COBRA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cobra=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cobra?=		build

BUILDLINK_API_DEPENDS.go-cobra+=	go-cobra>=0.0
BUILDLINK_PKGSRCDIR.go-cobra?=		../../devel/go-cobra

.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-viper/buildlink3.mk"
.include "../../textproc/go-md2man/buildlink3.mk"
.endif  # GO_COBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cobra

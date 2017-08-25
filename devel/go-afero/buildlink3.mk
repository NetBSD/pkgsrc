# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:11 jperkin Exp $

BUILDLINK_TREE+=	go-afero

.if !defined(GO_AFERO_BUILDLINK3_MK)
GO_AFERO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-afero=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-afero?=		build

BUILDLINK_API_DEPENDS.go-afero+=	go-afero>=0.0
BUILDLINK_PKGSRCDIR.go-afero?=		../../devel/go-afero

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-sftp/buildlink3.mk"
.include "../../devel/go-fs/buildlink3.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.endif  # GO_AFERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-afero

# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-i18n

.if !defined(GO_I18N_BUILDLINK3_MK)
GO_I18N_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-i18n=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-i18n?=		build

BUILDLINK_API_DEPENDS.go-i18n+=		go-i18n>=1.8.1
BUILDLINK_PKGSRCDIR.go-i18n?=		../../devel/go-i18n

.include "../../www/go-toml-pelletier/buildlink3.mk"
.endif  # GO_I18N_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-i18n

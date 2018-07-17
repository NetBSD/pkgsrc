# $NetBSD: buildlink3.mk,v 1.4 2018/07/17 03:51:22 minskim Exp $

BUILDLINK_TREE+=	go-i18n

.if !defined(GO_I18N_BUILDLINK3_MK)
GO_I18N_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-i18n=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-i18n?=		build

BUILDLINK_API_DEPENDS.go-i18n+=		go-i18n>=1.10.0
BUILDLINK_PKGSRCDIR.go-i18n?=		../../devel/go-i18n

.include "../../devel/go-yaml/buildlink3.mk"
.include "../../www/go-toml-pelletier/buildlink3.mk"
.endif  # GO_I18N_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-i18n

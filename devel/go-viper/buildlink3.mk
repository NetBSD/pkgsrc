# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-viper

.if !defined(GO_VIPER_BUILDLINK3_MK)
GO_VIPER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-viper=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-viper?=		build

BUILDLINK_API_DEPENDS.go-viper+=	go-viper>=0.0
BUILDLINK_PKGSRCDIR.go-viper?=		../../devel/go-viper

.include "../../www/go-toml-pelletier/buildlink3.mk"
.include "../../devel/go-fsnotify/buildlink3.mk"
.include "../../lang/go-hcl/buildlink3.mk"
.include "../../devel/go-properties/buildlink3.mk"
.include "../../devel/go-mapstructure/buildlink3.mk"
.include "../../devel/go-cast/buildlink3.mk"
.include "../../devel/go-jwalterweatherman/buildlink3.mk"
.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../devel/go-consul-api/buildlink3.mk"
.include "../../databases/go-etcd/buildlink3.mk"
.include "../../security/go-crypt/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../devel/go-afero/buildlink3.mk"
.endif  # GO_VIPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-viper

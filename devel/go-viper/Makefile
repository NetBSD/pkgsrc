# $NetBSD: Makefile,v 1.2 2017/08/25 16:49:14 jperkin Exp $

DISTNAME=	viper-0.0.20170723
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	25b30aa063fc18e48662b86996252eabdcf2f0c7
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/viper
COMMENT=	Go configuration with fangs
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/viper

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
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.38 2022/08/19 08:39:39 leot Exp $

DISTNAME=	node_exporter-1.3.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/prometheus/node_exporter
COMMENT=	Prometheus exporter for hardware and OS metrics
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision=${PKGREVISION} \
			-X github.com/prometheus/common/version.Branch=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.58 2023/11/10 15:45:21 bsiegert Exp $

DISTNAME=	node_exporter-1.6.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	4
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/prometheus/node_exporter
COMMENT=	Prometheus exporter for hardware and OS metrics
LICENSE=	apache-2.0

RCD_SCRIPTS=	node_exporter

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/prometheus/common/version.Version=${PKGVERSION_NOREV} \
			-X github.com/prometheus/common/version.Revision=${PKGREVISION} \
			-X github.com/prometheus/common/version.Branch=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

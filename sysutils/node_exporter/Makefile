# $NetBSD: Makefile,v 1.64 2024/06/01 14:03:02 bsiegert Exp $

DISTNAME=	node_exporter-1.7.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	5
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

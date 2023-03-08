# $NetBSD: Makefile,v 1.48 2023/03/08 13:38:54 bsiegert Exp $

DISTNAME=	node_exporter-1.4.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
PKGREVISION=	7
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

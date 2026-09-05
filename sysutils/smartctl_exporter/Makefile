# $NetBSD: Makefile,v 1.3 2026/09/05 19:10:02 bsiegert Exp $

DISTNAME=	smartctl_exporter-0.14.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus-community/smartctl_exporter/
COMMENT=	Prometheus exporter for sysutils/smartmontools
LICENSE=	apache-2.0

RCD_SCRIPTS=	smartctl_exporter

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

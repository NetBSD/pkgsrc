# $NetBSD: Makefile,v 1.23 2026/07/08 18:32:34 bsiegert Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.98.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	4c2110d6535b7fb5e031520d6ac55bea5c7ae865

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://tailscale.com/
COMMENT=	Wireguard-based VPN client for tailscale
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscale
GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscaled

RCD_SCRIPTS+=	tailscaled

GOFLAGS=      -ldflags "-X tailscale.com/version.longStamp=${PKGVERSION} \
	    -X tailscale.com/version.shortStamp=${PKGVERSION}"

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

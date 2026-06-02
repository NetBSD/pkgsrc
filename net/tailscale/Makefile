# $NetBSD: Makefile,v 1.20 2026/06/02 13:48:00 ktnb Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.98.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	235dbc84c51749d989ba6fe6485340bbf2a3ba04

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

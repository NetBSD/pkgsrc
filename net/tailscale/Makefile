# $NetBSD: Makefile,v 1.19 2026/05/22 13:55:21 ktnb Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.98.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	4eed3aface8fef453ac4d7ea3bd782b969834aa2

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

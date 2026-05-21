# $NetBSD: Makefile,v 1.18 2026/05/21 13:40:25 ktnb Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.98.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	1fdd2939b5c79620e7f0a00bdd411a061dcef9ac

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

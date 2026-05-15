# $NetBSD: Makefile,v 1.16 2026/05/15 20:26:35 ktnb Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.96.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	f86a9ab65341bbaabc330bd3bc9063b753f45304

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://tailscale.com/
COMMENT=	Wireguard-based VPN client for tailscale
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscale
GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscaled

RCD_SCRIPTS+=	tailscaled

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

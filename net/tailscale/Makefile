# $NetBSD: Makefile,v 1.12 2026/03/06 21:07:58 bsiegert Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.81.0pre20250210
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ryoon/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	1534583f2484f75450dd73f67949f61f26dbf340

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://tailscale.com/
COMMENT=	Wireguard-based VPN client for tailscale
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscale
GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscaled

RCD_SCRIPTS+=	tailscaled

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

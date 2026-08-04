# $NetBSD: Makefile,v 1.27 2026/08/04 19:03:05 ktnb Exp $

DISTNAME=	tailscale
PKGNAME=	tailscale-1.102.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NuclearKev/}
GITHUB_PROJECT=	tailscale
GITHUB_TAG=	7718ab0861b934c2a0daa2bcff47cc5ac5243bba

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://tailscale.com/
COMMENT=	Wireguard-based VPN client for tailscale
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscale
GO_BUILD_PATTERN+=	tailscale.com/cmd/tailscaled

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	paths/paths_unix.go paths/paths.go
SUBST_VARS.paths=	VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/db/tailscale ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS+=	tailscaled

GOFLAGS=	-ldflags "-X tailscale.com/version.longStamp=${PKGVERSION_NOREV} \
		-X tailscale.com/version.shortStamp=${PKGVERSION_NOREV}"

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

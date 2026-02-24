# $NetBSD: Makefile,v 1.23 2026/02/24 08:45:34 bsiegert Exp $

DISTNAME=	wireguard-go-0.0.20250522
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.zx2c4.com/wireguard-go/about/
COMMENT=	Implementation of WireGuard in Go
LICENSE=	mit

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/wireguard \
		${DESTDIR}${PREFIX}/bin/wireguard-go

GO_BUILD_PATTERN=	.

pre-patch:
	cd ${WRKSRC}/tun && ${LN} tun_openbsd.go tun_netbsd.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

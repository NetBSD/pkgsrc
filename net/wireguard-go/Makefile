# $NetBSD: Makefile,v 1.3 2024/02/07 14:50:56 bsiegert Exp $

DISTNAME=	wireguard-go-0.0.20230223
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.wireguard.com/
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

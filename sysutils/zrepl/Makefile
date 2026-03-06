# $NetBSD: Makefile,v 1.8 2026/03/06 21:08:05 bsiegert Exp $

DISTNAME=	zrepl-0.6.1
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=zrepl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zrepl/zrepl/
COMMENT=	One-stop ZFS backup & replication solution
LICENSE=	mit

ZREPL_FLAGS+=	-X github.com/zrepl/zrepl/version.zreplVersion=${PKGVERSION_NOREV}

GOFLAGS+=		-ldflags "${ZREPL_FLAGS}" -mod=readonly
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
